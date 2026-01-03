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

  ll N; cin >> N;
  // @InpVec(N, A) [SAuTIr8Y]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [SAuTIr8Y]
  vector<pll> B(N);
  REP(i, 0, N) B[i] = pll(A[i], i);
  ranges::sort(B);
  auto [x, i0] = B[N / 2];
  ll s = 0;
  REP(i, N / 2, N) s += B[i].first;
  vector<ll> C(N);
  REP(i, 0, N) {
    if (A[i] < x or (A[i] == x and i < i0)) C[i] = 1;
    else C[i] = -1;
  }
  vector<ll> D(N + 1);
  REP(i, 0, N) D[i + 1] = D[i] + C[i];
  ll i1 = min_element(ALL(D)) - D.begin();
  if (i1 == N) i1 = 0;
  cout << i1 << " " << s << endl;

  return 0;
}

