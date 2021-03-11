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

ll N, K;
constexpr ll maxN = 1e5;
vector<ll> s(maxN+1);
vector<ll> a(maxN+1);

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> K;
  s.at(0) = 0;
  for (ll i = 1; i <= N; i++) {
    ll xx;
    cin >> xx;
    a.at(i) = xx;
    s.at(i) = s.at(i-1) + xx;
  }
  if (s.at(N) < K) {
    cout << 0 << endl;
    return 0;
  }
  ll j;
  ll ans = 0;
  ll t = 0;
  for (j = 0; j <= N; j++) {
    if (s.at(j) >= K) break;
  }
  ans += N - j + 1;
  t = s.at(j);
  for (ll i = 2; i <= N; i++) {
    t -= a.at(i-1);
    if (t >= K) {
      // do nothing
    }else {
      j += 1;
      for (; j <= N; j++) {
	t += a.at(j);
	if (t >= K) break;
      }
      if (j > N) break;
    }
    ans += N - j + 1;
  }
  cout << ans << endl;

  return 0;
}

