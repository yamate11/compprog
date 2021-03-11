#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, K; cin >> N >> K;
  int ans;
  if (N % K == 0) ans = 0;
  else ans = 1;
  cout << ans << endl;

  return 0;
}

