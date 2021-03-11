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
  ll n, q;
  string s;
  cin >> n >> q >> s;
  vector<char> t(q);
  vector<char> d(q);
  for (ll i = 0; i < q; i++) {
    cin >> t.at(i) >> d.at(i);
  }
  ll c1 = 0;
  for (ll i = q-1; i >= 0; i--) {
    if ((d.at(i) == 'L') && (c1 < n) && (t.at(i) == s.at(c1))) {
      c1++;
    }else if ((d.at(i) == 'R') && (c1 > 0) && (t.at(i) == s.at(c1-1))) {
      c1--;
    }
  }
  ll c2 = n-1;
  for (ll i = q-1; i >= 0; i--) {
    if ((d.at(i) == 'R') && (c2 >= 0) && (t.at(i) == s.at(c2))) {
      c2--;
    }else if ((d.at(i) == 'L') && (c2+1 < n) && (t.at(i) == s.at(c2+1))) {
      c2++;
    }
  }
  cout << c2-c1+1 << endl;
  return 0;
}

