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
constexpr ll maxN = 50;
vector<ll> x(maxN), y(maxN);
map<pair<ll, ll>, int> tmap;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x.at(i);
    cin >> y.at(i);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      ll dx = x.at(i) - x.at(j);
      ll dy = y.at(i) - y.at(j);
      if (dy < 0 || (dy == 0 && dx < 0)) {
	dx = -dx;
	dy = -dy;
      }
      DLOG("p = (%lld, %lld)", dx, dy);
      auto p = make_pair(dx, dy);
      tmap[p] += 1;
    }
  }
  int vmax = 0;
  for (auto it = tmap.begin(); it != tmap.end(); it++) {
    vmax = max(vmax, it->second);
  }
  cout << N - vmax << endl;

  return 0;
}

