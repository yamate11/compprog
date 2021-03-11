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

ll N;
vector<ll> s;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  s.resize(N);
  for (ll i = 0; i < N; i++)  cin >> s.at(i);
  ll answer = 0;
  for (ll t = 1; t <= (N-2)/2; t++) {
    ll lim;
    if ((N-1) % t == 0) {
      lim = ((N-1) / t - 1) / 2;
    }else {
      lim = (N-1) / t - 1;
    }
    ll sum = 0;
    for (ll i = 1; i <= lim; i++) {
      sum += s.at(i*t) + s.at(N-1 - i*t);
      DLOG("t = %lld, i = %lld, sum = %lld", t, i, sum);
      answer = max(answer, sum);
    }
  }
  cout << answer << endl;

  return 0;
}

