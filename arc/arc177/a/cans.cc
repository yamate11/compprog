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

  vector U{500, 100, 50, 10, 5, 1};
  vector V(6, 0LL);
  REP(i, 0, 6) cin >> V[i];
  reverse(ALL(V));
  ll N; cin >> N;
  // @InpVec(N, X) [yoIhm8dy]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [yoIhm8dy]
  
  REP(i, 0, N) {
    ll x = X[i];
    REP(j, 0, 6) {
      ll a = x / U[j];
      if (a <= V[j]) {
        x -= a * U[j];
        V[j] -= a;
      }else {
        x -= V[j] * U[j];
        V[j] = 0;
      }
    }
    if (x > 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

