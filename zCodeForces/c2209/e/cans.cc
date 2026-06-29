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

// ---- inserted library file strSearch.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/strSearch.cc

vector<int> zAlg(const string& s) {
  int n = s.size();
  vector<int> z(n);
  z.at(0) = n;
  int i = 1;
  int j = 0;
  while (i < n) {
    for ( ; i+j < n && s.at(j) == s.at(i+j); j++) {}
    z.at(i++) = j;
    if (j > 0) {
      for (int k = 1; i < n && z.at(k) < j-1; k++, j--, i++) z.at(i) = z.at(k);
      j--;
    }
  }
  return z;
}

// matches("abab", "xababab") --> [1,3]
vector<int> matches(string p, string s, char sepChar = '\xff') {
  auto v = zAlg(p + string(1, sepChar) + s);
  int n = p.size();
  vector<int> res;
  for (size_t i = 0; i < s.size() - (n-1); i++) {
    if (v.at(n+1 + i) == n) res.push_back(i);
  }
  return res;
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, Q; cin >> N >> Q;
    string s; cin >> s;
    REP(_q, 0, Q) {
      ll l, r; cin >> l >> r; l--;
      auto zvec = zAlg(s.substr(l, r - l));
      vector<pll> st;
      ll ans = 0;
      REPrev(i, r - l - 1, 0) {
        ll a = zvec[i];
        if (a > 0) {
          while (not st.empty()) {
            auto [j, len] = st.back();
            if (i + a < j) break;
            st.pop_back();
            if (i + a <= j + len) {
              a = j + len - i;
              break;
            }
          }
          st.emplace_back(i, a);
          ans += a;
        }
      }
      cout << ans << "\n";
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

