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

  ll N, M, Q; cin >> N >> M >> Q;
  assert(N == 1000 and M == 10 and Q == 950);

  auto f = [&](auto& vec) {
    vector grps(2, vector<ll>());
    ll g = 0;
    grps[0].push_back(vec[0]);
    REP(i, 0, 10) {
      cout << "? " << vec[i] + 1 << " " << vec[i + 1] + 1 << endl;
      ll resp; cin >> resp;
      if (resp == 0) {
        grps[g].push_back(vec[i + 1]);
      }else {
        g = 1 - g;
        grps[g].push_back(vec[i + 1]);
      }
    }
    if (ssize(grps[0]) < ssize(grps[1])) swap(grps[0], grps[1]);
    return make_pair(move(grps[0]), move(grps[1]));
  };

  ll white = -1;
  vector<vector<ll>> cands1, cands2;
  REP(i, 0, 91) {
    vector<ll> vec;
    if (i < 90) {
      REP(j, 0, 11) vec.push_back(i * 11 + j);
    }else {
      REP(j, 0, 10) vec.push_back(i * 11 + j);
      vec.push_back(white);
    }
    auto [grp1, grp2] = f(vec);
    if (white < 0 and grp2.empty()) white = grp1[0];
    if (not grp2.empty()) {
      cands1.push_back(move(grp1));
      cands2.push_back(move(grp2));
    }
  }
  ll sz = ssize(cands1);
  REP(x, 0, 1LL << sz) {
    ll cnt = 0;
    REP(i, 0, sz) {
      if (x >> i & 1) cnt += ssize(cands1[i]);
      else            cnt += ssize(cands2[i]);
    }
    if (cnt == 10) {
      vector<ll> ans;
      REP(i, 0, sz) {
        if (x >> i & 1) for (ll e : cands1[i]) ans.push_back(e);
        else            for (ll e : cands2[i]) ans.push_back(e);
      }
      cout << "!";
      for (ll e : ans) cout << " " << e + 1;
      cout << endl;
      return 0;
    }
  }
  assert(0);

  return 0;
}

