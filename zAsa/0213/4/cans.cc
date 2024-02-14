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
  // @InpVec(N, A, dec=1) [hioznvMB]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [hioznvMB]

  ll lim = 2e5;

  vector<ll> cnt(lim);
  REP(i, 0, N) cnt[A[i]]++;
  vector<ll> S(lim + 1);
  REP(i, 0, lim) S[i + 1] = S[i] + cnt[i];
  vector<ll> T(lim);
  REP(i, 0, lim) T[i] = cnt[i] * S[i];
  vector<ll> W(lim + 1);
  REP(i, 0, lim) W[i + 1] = W[i] + T[i];
  vector<ll> Z(lim);
  REP(i, 0, lim) Z[i] = W[i] * cnt[i];
  ll ans = accumulate(ALL(Z), 0LL);
  cout << ans << endl;

  return 0;
}

