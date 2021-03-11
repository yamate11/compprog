#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
  ll tot = 0;
  for (ll i = N-1; i >= 0; i--) {
    ll x = (tot + A.at(i)) % B.at(i);
    if (x == 0) continue;
    tot += B.at(i) - x;
  }
  cout << tot << endl;
	  
  

  return 0;
}

