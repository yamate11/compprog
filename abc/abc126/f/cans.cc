#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
  #define DFUNC(fname, ...) fname(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFUNC(fname, ...)
#endif

ll M, K;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> M >> K;
  
  if ((1 << M) <= K) {
    cout << -1 << endl;
    return 0;
  }

  if (M == 1) {
    if (K == 0) {
      cout << "0 0 1 1" << endl;
    }else {
      cout << -1 << endl;
    }
    return 0;
  }

  cout << K;
  for (ll i = 0; i < (1 << M); i++) {
    if (i == K)  continue;
    cout << " " << i;
  }
  cout << " " << K;
  for (ll i = (1<<M) - 1; i >= 0; i--) {
    if (i == K)  continue;
    cout << " " << i;
  }
  cout << endl;

  return 0;
}

