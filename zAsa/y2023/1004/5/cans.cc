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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N); REP(i, 0, N) cin >> A[i];
  vector<ll> S(N + 1); REP(i, 0, N) S[i + 1] = S[i] + A[i];
  ll c; for (c = 0; c + 2 <= N and S[c + 1] + 2 * c < S[N] - S[c + 2] + N - 3; c += 2);
  ll ans = 0;
  REP(j, 1, c) ans += (A[c - j] + 1) * j;
  ans += A[0] * c;
  REP(j, 1, N - 1 - c) ans += (A[c + j] + 1) * j;
  ans += A[N - 1] * (N - 1 - c);
  cout << ans << endl;
  return 0;
}

