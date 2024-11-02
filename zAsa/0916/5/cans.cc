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

  ll Q, L; cin >> Q >> L;
  ll cnt = 0;
  vector<pll> S;
  REP(_q, 0, Q) {
    string op; cin >> op;
    if (op == "Push") {
      ll n, m; cin >> n >> m;
      S.emplace_back(m, n);
      cnt += n;
      if (cnt > L) {
        cout << "FULL\n";
        return 0;
      }
    }else if (op == "Pop") {
      ll n; cin >> n;
      cnt -= n;
      if (cnt < 0) {
        cout << "EMPTY\n";
        return 0;
      }
      while (true) {
        auto [mt, nt] = S.back(); S.pop_back();
        if (nt < n) {
          n -= nt;
        }else if (nt == n) {
          break;
        }else {
          S.emplace_back(mt, nt - n);
          break;
        }
      }
    }else if (op == "Top") {
      if (cnt == 0) {
        cout << "EMPTY\n";
        return 0;
      }
      auto [mt, nt] = S.back();
      cout << mt << "\n";
    }else if (op == "Size") {
      cout << cnt << "\n";
    }else assert(0);
  }
  cout << "SAFE\n";
  return 0;
}

