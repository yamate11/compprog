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
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  if (N % 2 == 1) {
    ll m = N / 2;
    ll s = A.at(m);
    ll l = B.at(m);
    cout << l - s + 1 << endl;
  }else {
    ll m = N / 2;
    ll s = A.at(m - 1) + A.at(m);
    ll l = B.at(m - 1) + B.at(m);
    cout << l - s + 1 << endl;
  }

  return 0;
}

