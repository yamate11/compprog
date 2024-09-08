#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, Q; cin >> H >> W >> Q;
  set<ll> h_full, v_full;
  REP(i, 0, W) h_full.insert(i);
  REP(i, 0, H) v_full.insert(i);
  vector horiz(H, h_full);
  vector vert(W, v_full);
  ll rem = H * W;
  REP(_q, 0, Q) {
    ll r, c; cin >> r >> c; r--; c--;
    auto it0 = horiz[r].lower_bound(c);
    if (it0 != horiz[r].end() and *it0 == c) {
      horiz[r].erase(it0);
      vert[c].erase(r);
      rem--;
    }else {
      vector<pll> to_erase;
      if (it0 != horiz[r].end()) {
        to_erase.emplace_back(r, *it0);
      }
      if (it0 != horiz[r].begin()) {
        it0--;
        to_erase.emplace_back(r, *it0);
      }
      auto it1 = vert[c].lower_bound(r);
      if (it1 != vert[c].end()) {
        to_erase.emplace_back(*it1, c);
      }
      if (it1 != vert[c].begin()) {
        it1--;
        to_erase.emplace_back(*it1, c);
      }
      rem -= ssize(to_erase);
      for (auto [r1, c1] : to_erase) {
        horiz[r1].erase(c1);
        vert[c1].erase(r1);
      }
    }
  }
  cout << rem << endl;

  return 0;
}

