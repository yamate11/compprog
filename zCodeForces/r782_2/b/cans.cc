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

  auto solve = [&]() -> void {
    ll N, K; cin >> N >> K;
    string S; cin >> S;
    vector<ll> ans(N);
    if (K % 2 == 0) {
      REP(i, 0, N - 1) {
        if (S[i] == '0') {
          if (K > 0) {
            ans[i] = 1;
            S[i] = '1';
            K--;
          }
        }
      }
      ans[N - 1] = K;
      if (K % 2 == 1) {
        if (S[N - 1] == '1') S[N - 1] = '0';
        else S[N - 1] = '1';
      }
    }else {
      REP(i, 0, N - 1) {
        if (S[i] == '1') {
          if (K > 0) {
            ans[i] = 1;
            S[i] = '1';
            K--;
          }else {
            S[i] = '0';
          }
        }else {
          S[i] = '1';
        }
      }
      ans[N - 1] = K;
      if (K % 2 == 0) {
        if (S[N - 1] == '1') S[N - 1] = '0';
        else S[N - 1] = '1';
      }
    }
    cout << S << "\n";
    REPOUT(i, 0, N, ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

