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

  ll N, X, Y; cin >> N >> X >> Y;
  ll se = 0;
  ll so = 0;
  // @InpVec(N, A) [cDjHGOqw]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [cDjHGOqw]
  REP(i, 0, N) {
    if (i % 2 == 0) se += A[i];
    else so += A[i];
  }
  auto f = [&](ll u, ll v, ll i0, ll n0) -> bool {
    if ((u + v) % 2 != 0) return false;
    if (u + v < 0) return false;
    ll S = (u + v) / 2;
    vector<bool> T(S + 1);
    T[0] = true;
    REP(ii, 0, n0) {
      ll i = 2 * ii + i0;
      REP(j, 0, S + 1) {
        if (T[j] and j + A[i] <= S) T[j + A[i]] = true;
      }
    }
    return T[S];
  };
  bool be = f(X - A[0], se - A[0], 2, (N - 1) / 2);
  bool bo = f(Y, so, 1, N / 2);
  if (be and bo) cout << "Yes\n";
  else cout << "No\n";


  return 0;
}

