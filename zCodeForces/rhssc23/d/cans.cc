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
    ll N; cin >> N;
    vector A(N, vector(N, 0LL));
    REP(i, 0, N) {
      string s; cin >> s;
      REP(j, 0, N) A[i][j] = s[j] - '0';
    }
    vector<ll> in(2 * N, 0LL);
    vector<ll> out(2 * N, 0LL);
    ll ans = 0;
    REP(i, 0, N) {
      vector<ll> B(N);
      ll t = 0;
      REP(j, 0, i) t += in[j];
      REP(j, 0, N) {
        t += in[i + j];
        B[j] = (t + A[i][j]) % 2;
        t += out[j - i + N];
      }
      REP(j, 0, N) {
        if (B[j] != 0) {
          ans++;
          in[i + j]++;
          out[j - i + N]++;
        }
      }
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

