#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  string S; cin >> S;
  int N = S.size();
  ll cnt = 2LL * (N-1);
  for (ll i = 1; i < N - 1; i++) {
    if (S.at(i) == 'U') cnt += 2LL * i + (N-1 - i);
    else                cnt += i + 2LL * (N-1 - i);
  }
  cout << cnt << endl;
  return 0;
}

