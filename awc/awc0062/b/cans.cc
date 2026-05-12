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

  ll N, K, G; cin >> N >> K >> G;
  // @InpMVec(N, (D, T)) [gli04OyA]
  auto D = vector(N, ll());
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; D[i] = v1;
    ll v2; cin >> v2; T[i] = v2;
  }
  // @End [gli04OyA]
  
  ll totT = accumulate(ALL(T), 0LL);

  vector<ll> S(N + 1);
  REP(i, 0, N) S[i + 1] = S[i] + T[i];
  ll mx = 0;
  REP(i, 0, N - K + 1) mx = max(mx, S[i + K] - S[i]);
  cout << G + totT - mx << endl;

  return 0;
}

