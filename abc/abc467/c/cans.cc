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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [VeUfVpQf]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [VeUfVpQf]
  // @InpVec(N - 1, B) [QW4HUqNX]
  auto B = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; B[i] = v; }
  // @End [QW4HUqNX]

  vector<ll> C;
  REP(i, 0, N - 1) {
    if ((A[i] + A[i + 1] - B[i]) % 2 != 0) C.push_back(i);
  }
  ll x = 0, y = 0;
  ll K = ssize(C);
  REP(i, 0, K) {
    if (i == 0) x += C[i] + 1;
    else if (i % 2 == 0) x += C[i] - C[i - 1];
    else y += C[i] - C[i - 1];
  }
  if (K >= 1) {
    if (K % 2 == 0) x += N - 1 - C[K - 1];
    else y += N - 1 - C[K - 1];
  }
  cout << min(x, y) << endl;
    


  return 0;
}

