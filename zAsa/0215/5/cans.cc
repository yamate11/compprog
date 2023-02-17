#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  vector<pll> st;
  ll size = 0;
  REP(_q, 0, Q) {
    string tp; cin >> tp;
    if (tp == "Push") {
      ll n, m; cin >> n >> m;
      st.emplace_back(m, n);
      size += n;
      if (size > L) {
        cout << "FULL\n";
        return 0;
      }
    }else if (tp == "Pop") {
      ll n; cin >> n;
      size -= n;
      while (n > 0) {
        if (st.empty()) {
          cout << "EMPTY\n";
          return 0;
        }
        auto [a, cnt] = st.back(); st.pop_back();
        if (cnt > n) {
          st.emplace_back(a, cnt - n);
          break;
        }else if (cnt == n) {
          break;
        }else if (cnt < n) {
          n -= cnt;
        }else assert(0);
      }
    }else if (tp == "Top") {
      if (st.empty()) {
        cout << "EMPTY\n";
        return 0;
      }
      auto [a, cnt] = st.back();
      cout << a << "\n";
    }else if (tp == "Size") {
      cout << size << "\n";
    }else assert(0);
  }
  cout << "SAFE\n";

  return 0;
}

