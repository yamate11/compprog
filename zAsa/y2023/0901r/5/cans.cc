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
  // @InpVec(N, A) [R7CP5kOY]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [R7CP5kOY]
  auto ord = vector(N, ll());
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](ll i, ll j) -> bool { return A[i] < A[j]; });
  auto C = vector(N, 0LL);
  REP(i, 0, N / 2) {
    C[ord[i]] = -1;
    C[ord[N / 2 + i]] = 1;
  }
  auto D = vector(N + 1, 0LL);
  REP(i, 0, N) D[i + 1] = D[i] + C[i];
  assert(D[N] == 0);
  ll k = max_element(D.begin(), prev(D.end())) - D.begin();
  ll s = 0;
  REP(i, 0, N / 2) s += A[ord[N / 2 + i]];
  cout << k << " " << s << endl;

  return 0;
}
