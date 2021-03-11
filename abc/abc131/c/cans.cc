#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 0

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#if DEBUG
  #define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DCALL(func, ...)
#endif

constexpr ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

ll A, B, C, D;
ll g;
ll l;

ll upto(ll p) {
  return p - ((p + C - 1) / C + (p + D - 1) / D - 1);
}

ll adNum(ll x) {
  ll k = x / l;
  ll m = x % l;
  if (m == 0) {
    return k * upto(l);
  }else {
    return k * upto(l) + upto(m);
  }
}


int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> A >> B >> C >> D;
  ll dummy1, dummy2;
  g = eGCD(C, D, dummy1, dummy2);
  l = C * D / g;
  ll answer = adNum(B+1) - adNum(A);
  cout << answer << endl;

  return 0;
}

