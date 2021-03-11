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

ll N, K;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> K;
  cout << N - K + 1 << endl;

  return 0;
}

