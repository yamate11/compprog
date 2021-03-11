#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  for (ll i = 0; i < N; i++) cin >> B.at(i);
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  // max_x { #{ a*b | a*b < x } < K }

  ll lo = 1;
  ll hi = (ll)(1e18) + 1;
  while (lo + 1 < hi) {
    ll mid = (lo + hi) / 2;
    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
      auto it = lower_bound(B.begin(), B.end(), (mid + A.at(i) - 1) / A.at(i));
      cnt += it - B.begin();
    }
    if (cnt < K) lo = mid;
    else         hi = mid;
  }
  cout << lo << endl;

  return 0;
}

