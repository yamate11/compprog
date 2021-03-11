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

ll A,B;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> A >> B;
  ll x;
  if (A >= 13)  x = B;
  else if (A >= 6)  x = B / 2;
  else  x = 0;
  cout << x << endl;

  return 0;
}

