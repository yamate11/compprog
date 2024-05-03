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

  ll N, x; cin >> N >> x;
  // @InpVec(N, A) [GWfDlzsf]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [GWfDlzsf]
  sort(ALL(A));
  ll s = 0;
  ll i = 0;
  while (i < N) {
    s += A[i];
    if (s > x) {
      cout << i << endl;
      return 0;
    }
    i++;
  }
  if (s == x) {
    cout << N << endl;
  }else {
    cout << N - 1 << endl;
  }

  return 0;
}

