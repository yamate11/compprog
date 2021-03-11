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

constexpr ll maxH = 2000;
ll H, W;
vector<string> S(maxH);
vector<ll> p(maxH);

ll countDot(string s, ll pos) {
  ll r = s.find('#', pos);
  if (r == (ll)string::npos) {
    return s.size() - pos;
  }else {
    return r - pos;
  }
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    cin >> S.at(i);
    p.at(i) = -1;
  }
  ll ans = 0;
  for (int x = 0; x < W; x++) {
    DLOG("x = %d", x);
    int vlen = -1;
    for (int y = 0; y < H; y++) {
      DLOG("y = %d", y);
      if (S.at(y).at(x) == '#') {
	vlen = -1;
	p.at(y) = -1;
	continue;
      }
      if (vlen < 0) {
	vlen = 1;
	for (int j = y+1; j < H; j++) {
	  if (S.at(j).at(x) == '.')  vlen++;
	  else  break;
	}
      }
      if (p.at(y) < 0) {
	p.at(y) = countDot(S.at(y), x);
      }
      ll val = vlen + p.at(y) - 1;
      DLOG("val = %lld, vlen = %d, p.at(%d) = %lld", val, vlen, y, p.at(y));
      ans = max(ans, val);
    }
  }
  cout << ans << endl;

  return 0;
}

