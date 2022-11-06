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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, P) [6m6j7fV6]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [6m6j7fV6]
  ll i = N - 2;
  for (; i >= 0; i--) if (P[i] > P[i + 1]) break;
  ll j = i + 1;
  for (; j + 1 < N; j++) if (P[j + 1] > P[i]) break;
  vector<ll> A;
  REP(k, i, N) {
    if (k != j) A.push_back(P[k]);
  }
  sort(ALL(A), greater<ll>());
  REP(k, 0, i) cout << P[k] << " ";
  cout << P[j];
  for (ll k : A) cout << " " << k;
  cout << endl;


  return 0;
}

