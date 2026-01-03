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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [yJMfv65w]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [yJMfv65w]
  // @InpVec(N, B) [d2Gn5edI]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [d2Gn5edI]
  // @InpVec(N, C) [1k2HzT6U]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [1k2HzT6U]
  sort(ALL(A), greater<ll>());
  sort(ALL(B), greater<ll>());
  sort(ALL(C), greater<ll>());

  auto enc = [&](ll i, ll j, ll k) -> ll {
    return (i << 40) | (j << 20) | k;
  };

  using sta = tuple<ll, ll, ll, ll>;
  priority_queue<sta> pque;
  unordered_set<ll> seen;
  auto val = [&](ll i, ll j, ll k) -> ll { return A[i] * B[j] + B[j] * C[k] + C[k] * A[i]; };
  auto op = [&](ll i, ll j, ll k) -> void {
    if (i >= N or j >= N or k >= N) return;
    const auto& [_it, rc] = seen.insert(enc(i, j, k));
    if (not rc) return;
    pque.emplace(val(i, j, k), i, j, k);
  };
  op(0, 0, 0);
  ll kk = 0;
  while (not pque.empty()) {
    kk++;
    auto [x, i, j, k] = pque.top(); pque.pop();
    if (kk == K) {
      cout << x << endl;
      return 0;
    }
    op(i + 1, j, k);
    op(i, j + 1, k);
    op(i, j, k + 1);
  }
  

  return 0;
}

