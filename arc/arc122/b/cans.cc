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
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  double ans = 1e15;
  ll sum = 0;
  for (ll i = N-1; i >= 0; i--) {
    ll t = i + 1;
    ll s = N - t;
    double x = A[i] / 2.0;
    double e = (double)(sum + (t - s) * x) / (double)N;
    ans = min(ans, e);
    t--;
    s = N - t;
    sum += A[i];
    e = (double)(sum + (t - s) * x) / (double)N;
    ans = min(ans, e);
  }
  cout << ans << endl;

  return 0;
}

