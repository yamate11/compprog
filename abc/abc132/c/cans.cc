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
vector<ll> d;
constexpr ll maxD = 1e5;
vector<ll> cnt(maxD+1);

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N;
  d.resize(N);
  for (ll i = 0; i < N; i++) {
    ll tmp;
    cin >> tmp;
    cnt.at(tmp)++;
  }
  ll s = 0;
  ll ans = 0;
  for (ll i = 1; i <= maxD; i++) {
    s += cnt.at(i);
    if (s == N / 2) ans++;
  }
  cout << ans << endl;
  return 0;
}

