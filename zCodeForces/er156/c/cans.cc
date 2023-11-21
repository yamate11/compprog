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

  auto solve = [&]() -> char {
    string S; cin >> S;
    ll sz = SIZE(S);
    ll N; cin >> N;
    vector<char> st{(char)-1};
    ll idx = 0;
    ll len = sz;
    ll onum = N;
    while (true) {
      if (onum <= len) {
        if (onum < SIZE(st)) return st[1 + onum - 1];
        ll j = onum - 1 - (SIZE(st) - 1);
        return S[idx + j] ;
      }else {
        while (idx < sz and st.back() <= S[idx]) {
          st.push_back(S[idx++]);
        }
        st.pop_back();
        onum -= len;
        len--;
      }
    }
    assert(0);
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve();
  cout << "\n";

  return 0;
}

