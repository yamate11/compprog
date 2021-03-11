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
  ll n;
  string s;
  cin >> n >> s;
  ll red = 0;
  ll blue = 0;
  for (char c : s) {
    if (c == 'R')  red++;
    else           blue++;
  }
  string ans = red > blue ? "Yes" : "No";
  cout << ans << endl;
  return 0;
}

