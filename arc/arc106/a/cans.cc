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
  ll p = 1;
  ll a = 0;
  while (true) {
    if (p >= N / 3) break;
    a++;
    p *= 3;
    ll q = 1;
    ll b = 0;
    while (true) {
      if (q > (N - p) / 5) break;
      b++;
      q *= 5;
      if (p + q == N) {
	cout << a << " " << b << endl;
	return 0;
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

