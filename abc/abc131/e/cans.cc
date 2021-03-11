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

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N >> K;
  if (K > (N - 1) * (N - 2) / 2) {
    cout << "-1" << endl;
    return 0;
  }
  ll M = 0;
  vector<ll> u;
  vector<ll> v;
  for (ll i = 2; i <= N; i++) {
    u.push_back(1);
    v.push_back(i);
    M++;
  }
  ll t = 1;
  for (ll j = 2; j <= N; j++) {
    for (ll k = j + 1; k <= N; k++) {
      if (t > K) {
	u.push_back(j);
	v.push_back(k);
	M++;
      }
      t++;
    }
  }
  cout << M << "\n";
  for (ll i = 0; i < M; i++) {
    cout << u[i] << " " << v[i] << "\n";
  }

  return 0;
}

