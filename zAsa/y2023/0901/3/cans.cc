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

  ll N; cin >> N;
  // @InpVec(N, A) [J3uPp5ZT]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [J3uPp5ZT]

  ll ans = 0;
  enum kind { EMPTY, UNKNOWN, INC, DEC };
  kind mode = EMPTY;
  REP(i, 0, N) {
    if (mode == EMPTY) {
      ans++;
      mode = UNKNOWN;
    }else if (mode == UNKNOWN) {
      if (A[i - 1] < A[i]) mode = INC;
      else if (A[i - 1] > A[i]) mode = DEC;
    }else if (mode == INC and A[i - 1] > A[i]) {
      ans++;
      mode = UNKNOWN;
    }else if (mode == DEC and A[i - 1] < A[i]) {
      ans++;
      mode = UNKNOWN;
    }
  }
  cout << ans << endl;
  return 0;
}

