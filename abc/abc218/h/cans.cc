#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, R; cin >> N >> R;
  if (R > N / 2) R = N - R;
  vector<ll> A(N+1), B(N), P(N);
  for (ll i = 1; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) B[i] = A[i] + A[i + 1];
  using sta = tuple<ll, ll, ll>;
  priority_queue<sta> pque;
  for (ll i = 0; i < N; i++) {
    P[i] = i;
    pque.emplace(B[i], i, i);
  }
  ll ans = 0, cnt = 0;
  while (true) {
    auto [m, p, q] = pque.top(); pque.pop();
    if (P[p] != q || P[q] != p) continue;
    ans += m;
    if (++cnt == R) break;
    assert(! (q == N-1 && p == 0));
    if (q == N-1) {
      assert(p - 1 >= 0);
      P[p - 1] = -1;
    }else if (p == 0) {
      assert(q + 1 < N);
      P[q + 1] = -1;
    }else {
      ll u = P[p - 1];
      ll v = P[q + 1];
      ll new_m = B[u] + B[v] - m;
      pque.emplace(new_m, u, v);
      P[u] = v;
      P[v] = u;
      B[u] = B[v] = new_m;
    }
  }
  cout << ans << endl;

  return 0;
}

