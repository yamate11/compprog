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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  //@InpVec(N, A, base=1) [XwpSSPW2]
  auto A = vector(N + 1, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i + 1] = v; }
  // @End [XwpSSPW2]
  //@InpVec(N, B, base=1) [erjOsvpQ]
  auto B = vector(N + 1, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i + 1] = v; }
  // @End [erjOsvpQ]
  //@InpVec(N, C, base=1) [J6lFUQiS]
  auto C = vector(N + 1, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i + 1] = v; }
  // @End [J6lFUQiS]
  vector<ll> revC(N + 1);
  vector<ll> revB(N + 1);
  REP(i, 1, N + 1) revC[C[i]]++;
  REP(i, 1, N + 1) revB[B[i]] += revC[i];
  ll ans = 0;
  REP(i, 1, N + 1) ans += revB[A[i]];
  cout << ans << endl;

  return 0;
}

