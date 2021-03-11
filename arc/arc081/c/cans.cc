#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end(), greater<ll>());
  ll i = 0;
  ll x1 = 0;
  ll x2 = 0;
  while (i+1 < N) {
    if (A.at(i) == A.at(i+1)) {
      if (x1 == 0) {
	x1 = A.at(i);
      }else {
	x2 = A.at(i);
	break;
      }
      i += 2;
    }else {
      i ++;
    }
  }
  cout << x1 * x2 << endl;
  return 0;
}

