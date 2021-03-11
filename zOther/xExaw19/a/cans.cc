#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DLOG(...)
#endif

void debug(auto f) {
#if DEBUG
  f();
#endif
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  string ans = a == b && b == c ? "Yes" : "No";
  cout << ans << endl;
  return 0;
}

