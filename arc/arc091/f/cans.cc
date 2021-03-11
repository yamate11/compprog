#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


ll ceil(ll x, ll y) { return (x + (y-1)) / y; }

ll grundy(ll K, ll A) {
  if (A < K) return 0;
  ll m = ceil(A, K);
  if (A % K == 0) return m;
  ll x = ceil(A % K, m);
  return grundy(K, A - m * x);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll acc = 0;
  for (ll i = 0; i < N; i++) {
    ll a, k; cin >> a >> k;
    acc ^= grundy(k, a);
  }
  cout << (acc ? "Takahashi" : "Aoki") << endl;
  return 0;
}

