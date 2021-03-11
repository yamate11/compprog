#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K, M; cin >> N >> K >>M;
  ll s = 0;
  for (ll i = 0; i < N-1; i++) {
    ll a; cin >> a;
    s += a;
  }
  ll x = N * M - s;
  if (x < 0) {
    cout << "0\n";
  }else if (x > K) {
    cout << "-1\n";
  }else {
    cout << x << endl;
  }

  return 0;
}

