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

  ll N; cin >> N;
  vector A(2 * N, 0LL);
  ll tot = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    A[i] = A[N + i] = a;
    tot += a;
  }
  ll s = 0;
  ll p = 0;
  ll q = 0;
  ll ans = 2 * tot;
  while (p < 2*N) {
    while (p < 2*N && s + A[p] < tot - (s + A[p])) {
      s += A[p];
      p++;
    }
    ans = min(ans, abs(s - (tot - s)));
    if (p == 2*N) break;
    s += A[p];
    p++;
    ans = min(ans, abs(s - (tot - s)));
    while (q < 2*N && s - A[q] > tot - (s - A[q])) {
      s -= A[q];
      q++;
    }
    ans = min(ans, abs(s - (tot - s)));
    if (q == 2*N) break;
    s -= A[q];
    q++;
    ans = min(ans, abs(s - (tot - s)));
    if (q == 2*N) break;
  }
  cout << ans << endl;


  return 0;
}

