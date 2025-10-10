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
  ll sz = 0;
  vector<pll> vec;
  REP(q, 0, Q) {
    string op; cin >> op;
    if (op == "Push") {
      ll n, m; cin >> n >> m;
      if (sz > L - n) {
        cout << "FULL\n";
        return 0;
      }
      vec.emplace_back(m, n);
      sz += n;
    }else if (op == "Pop") {
      ll n; cin >> n;
      sz -= n;
      while (n > 0) {
        if (vec.empty()) {
          cout << "EMPTY\n";
          return 0;
        }
        auto [mm, nn] = vec.back(); vec.pop_back();
        if (nn > n) {
          vec.emplace_back(mm, nn - n);
          break;
        }else if (nn == n) {
          break;
        }else if (nn < n) {
          n -= nn;
        }else assert(false);
      }
    }else if (op == "Top") {
      if (vec.empty()) {
        cout << "EMPTY\n";
        return 0;
      }else {
        cout << vec.back().first << "\n";
      }
    }else if (op == "Size") {
      cout << sz << "\n";
    }else assert(false);
  }
  cout << "SAFE\n";
  return 0;
}

