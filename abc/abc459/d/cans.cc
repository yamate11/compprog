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

  auto solve = [&]() -> void {
    string S; cin >> S;
    ll N = ssize(S);
    ll n_alph = 26;
    vector C(n_alph, 0LL);
    for (char c : S) C[c - 'a']++;
    auto it = ranges::max_element(C);
    ll d = it - C.begin();
    ll x = *it;
    if (x > (N - x) + 1) {
      cout << "No\n";
    }else {
      cout << "Yes\n";
      string ans(N, '@');
      ll idx = 0;
      for (ll i = 0; i < N; i += 2) {
        if (C[d] > 0) {
          ans[i] = 'a' + d;
          C[d]--;
        }else {
          while (C[idx] == 0) idx++;
          ans[i] = 'a' + idx;
          C[idx]--;
        }
      }
      for (ll i = 1; i < N; i += 2) {
        while (C[idx] == 0) idx++;
        ans[i] = 'a' + idx;
        C[idx]--;
      }
      cout << ans << "\n";
    }
  };


  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

