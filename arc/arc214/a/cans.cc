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

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [hmjss5BE]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [hmjss5BE]

  REP(k, 0, 2*N - 1) {
    ll i0, len;
    if (k <= N - 1) {
      i0 = 0;
      len = k + 1;
    }else {
      i0 = k - (N - 1);
      len = 2*N - 1 - k;
    }
    char c0 = '.';
    REP(i, i0, i0 + len) {
      ll j = k - i;
      if (S[i][j] != '?') {
        if (c0 == '.') c0 = S[i][j];
        else {
          if (c0 == S[i][j]) {
          }else {
            cout << -1 << endl;
            return 0;
          }
        }
      }
    }
    if (c0 == '.') c0 = '0';
    REP(i, i0, i0 + len) {
      ll j = k - i;
      if (S[i][j] == '?') S[i][j] = c0;
    }
  }
  REP(i, 0, N) cout << S[i] << "\n";

  return 0;
}

