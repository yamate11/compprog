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

ll N;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  ll t = 0;
  while (N > 0) {
    t += N % 10;
    N /= 10;
  }
  if (t == 1)  t = 10;
  cout << t << endl;

  return 0;
}

