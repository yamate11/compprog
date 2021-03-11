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

string S;

bool maybeMonth(char c1, char c2) {
  ll x = (c1 - '0') * 10 + (c2 - '0');
  return ((1 <= x) && (x <= 12));
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> S;
  bool t1 = maybeMonth(S.at(0), S.at(1));
  bool t2 = maybeMonth(S.at(2), S.at(3));
  string answer;
  if (t1 && t2) {
    answer = string("AMBIGUOUS");
  }else if (t1 && !t2) {
    answer = string("MMYY");
  }else if (!t1 && t2) {
    answer = string("YYMM");
  }else {
    answer = string("NA");
  }
  cout << answer << endl;

  return 0;
}

