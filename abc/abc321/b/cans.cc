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

  ll N, X; cin >> N >> X;
  // @InpVec(N - 1, A) [37d6iOqk]
  auto A = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; A[i] = v; }
  // @End [37d6iOqk]

  REP(y, 0, 101) {
    auto B = A;
    B.push_back(y);
    sort(ALL(B));
    ll x = 0;
    REP(i, 1, N - 1) x += B[i];
    if (x >= X) {
      cout << y << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  

  return 0;
}

