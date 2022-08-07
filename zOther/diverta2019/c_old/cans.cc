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
ll ba = 0;
ll bx = 0;
ll xa = 0;
ll xx = 0;
ll inner = 0;
ll outer = 0;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  for (ll i = 0; i < N; i++)  {
    string s;
    cin >> s;
    for (ll j = 0; j < (ll) s.size()-1; j++) {
      if (s.at(j) == 'A' && s.at(j+1) == 'B') inner++;
    }

    if (s.at(0) == 'B') {
      if (s.at(s.size()-1) == 'A')  ba++;
      else                   bx++;
    }else {
      if (s.at(s.size()-1) == 'A')  xa++;
      else                   xx++;
    }

  }

  if (ba >= 1) {
    outer = ba - 1;
    if (xa >= 1) {
      outer += 1;
      xa -= 1;
    }
    if (bx >= 1) {
      outer += 1;
      bx -= 1;
    }
    outer += min(xa, bx);
  }else {
    outer = min(xa, bx);
  }

  cout << inner + outer << endl;

  return 0;
}

