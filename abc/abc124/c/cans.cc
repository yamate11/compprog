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

string S;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> S;
  ll even0 = 0;
  ll even1 = 0;
  ll odd0 = 0;
  ll odd1 = 0;
  for (ll i = 0; i < (ll) S.size(); i++) {
    if (i % 2 == 0) {
      if (S.at(i) == '0') {
	even0++;
      }else {
	even1++;
      }
    }else {
      if (S.at(i) == '0') {
	odd0++;
      }else {
	odd1++;
      }
    }
  }
  cout << min(even0 + odd1, even1 + odd0) << endl;

  return 0;
}

