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

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  ll n;
  vector<ll> p;
  

  cin >> n;
  p.resize(n);
  for (ll i = 0; i < n; i++) cin >> p.at(i);
  ll cnt = 0;
  for (ll i = 1; i < n-1; i++) {
    ll x = p.at(i-1);
    ll y = p.at(i);
    ll z = p.at(i+1);
    if ((x < y && y < z) || (x > y && y > z)) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

