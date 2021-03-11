#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X, Y; cin >> N >> X >> Y;
  ll c = Y - X + 1;
  ll a = X - 1;
  ll b = N - Y;
  vector<ll> cnt(N);

  for (ll i = 1; i < (c+1) / 2; i++) {
    cnt.at(i) += c;
  }
  if (c % 2 == 0) cnt.at(c/2) += c/2;

  for (ll i = 1; i < a; i++) cnt.at(i) += a - i;
  for (ll i = 1; i < b; i++) cnt.at(i) += b - i;
  // a-c
  for (ll i = 1; i <= a; i++) {
    cnt.at(i) += 1;
    for (ll j = 1; j < (c+1)/2; j++) {
      cnt.at(i+j) += 2;
    }
    if (c % 2 == 0) cnt.at(i + c/2) += 1;
  }
  // b-c
  for (ll i = 1; i <= b; i++) {
    cnt.at(i) += 1;
    for (ll j = 1; j < (c+1)/2; j++) {
      cnt.at(i+j) += 2;
    }
    if (c % 2 == 0) cnt.at(i + c/2) += 1;
  }
  // a-b
  for (ll i = 1; i <= a; i++) {
    for (ll j = 1; j <= b; j++) {
      cnt.at(i+j+1)++;
    }
  }
  for (ll i = 1; i <= N-1; i++) {
    cout << cnt.at(i) << "\n";
  }


  return 0;
}

