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

  ll N, X, Y; cin >> N >> X >> Y;


  // @InpVec(N, A) [A02zG0o8]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [A02zG0o8]
  // @InpVec(N, B) [2EV2GMks]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [2EV2GMks]

  auto f = [&](auto& vec, ll th) -> ll {
    sort(ALL(vec), greater<ll>());
    ll acc = 0;
    REP(i, 0, N) {
      acc += vec[i];
      if (acc > th) return i + 1;
    }
    return N;
  };

  ll p = f(A, X);
  ll q = f(B, Y);
  cout << min(p, q) << endl;

  return 0;
}

