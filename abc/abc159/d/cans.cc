#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0 ; i < N; i++) cin >> A.at(i);
  vector<ll> cnt(N+1);
  for (ll i = 0; i < N; i++) {
    cnt.at(A.at(i))++;
  }
  ll sum = 0;
  for (ll i = 1; i <= N; i++) {
    sum += cnt.at(i) * (cnt.at(i) - 1) / 2;
  }
  for (ll i = 0; i < N; i++) {
    ll j = A.at(i);
    ll y = cnt.at(j);
    ll x = sum - y * (y-1) / 2 + (y-1) * (y-2) / 2;
    cout << x << "\n";
  }

  return 0;
}

