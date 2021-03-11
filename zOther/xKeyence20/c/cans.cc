#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1e9;

  ll N, K, S; cin >> N >> K >> S;
  vector<ll> A(N);
  if (S < big) {
    for (ll i = 0; i < K; i++) A.at(i) = S;
    for (ll i = K; i < N; i++) A.at(i) = big;
  }else if (N == K) {
    for (ll i = 0; i < N; i++) A.at(i) = S;
  }else if (K == 0) {
    for (ll i = 0; i < N; i++) A.at(i) = 1;
  }else {
    for (ll i = 0; i < K-1; i++) A.at(i) = S;
    ll x = S / (N-(K-1));
    for (ll i = K-1; i < N-1; i++) A.at(i) = x;
    A.at(N-1) = S - x * (N-K);
  }
  for (ll i = 0; i < N; i++) {
    if (i == 0) cout << A.at(i);
    else        cout << " " << A.at(i);
  }
  cout << endl;

  return 0;
}

