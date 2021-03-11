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

ll N, M;
vector<vector<ll>> nbr;
ll S, T;

ll enc(ll level, ll i) { return level * N + (i-1); }
ll nl(ll level) { return (level + 1) % 3; }

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N >> M;
  nbr.resize(3*N);
  for (ll i = 0; i < M; i++) {
    ll u, v;  cin >> u >> v;
    for (ll level = 0; level < 3; level++) {
      nbr.at(enc(level, u)).push_back(enc(nl(level), v));
    }
  }
  cin >> S >> T;

  vector<ll> dist(3*N, -1);
  vector<bool> done(3*N);
  queue<ll> que;
  dist.at(enc(0, S)) = 0;
  que.push(enc(0, S));
  while (!que.empty()) {
    ll x = que.front(); que.pop();
    DLOG("qtop = %lld", x);
    if (done.at(x)) continue;
    for (ll y : nbr.at(x)) {
      if (dist.at(y) >= 0) continue;
      dist.at(y) = dist.at(x) + 1;
      que.push(y);
    }
    done.at(x) = true;
  }
  ll z = dist.at(enc(0, T));
  ll ans = z < 0 ? -1 : z / 3;
  cout << ans << endl;


  return 0;
}

