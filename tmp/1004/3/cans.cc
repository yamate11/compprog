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
  // @InpVec(3*N, A) [gfoRWpZ6]
  auto A = vector(3*N, ll());
  for (int i = 0; i < 3*N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [gfoRWpZ6]
  sort(ALL(A), greater<ll>());
  ll s = 0;
  REP(i, 0, N) s += A[2*i + 1];
  cout << s << endl;

  return 0;
}

