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

ll N, W;
constexpr ll maxN = 100;
vector<ll> val[4], acc[4];
ll wn[4];


int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N >> W;
  ll w0;
  ll w;
  ll v;
  cin >> w0 >> v;
  val[0].push_back(v);
  for (ll i = 1; i < N; i++) {
    cin >> w >> v;
    val[w - w0].push_back(v);
  }
  for (ll j = 0; j < 4; j++)  {
    sort(val[j].begin(), val[j].end(), greater<ll>());
  }
  for (ll j = 0; j < 4; j++) {
    acc[j].push_back(0);
    for (size_t i = 1; i <= val[j].size(); i++) {
      acc[j].push_back(acc[j][i-1] + val[j][i-1]);
    }
  }
  ll answer = 0;
  for (size_t i0 = 0; i0 <= val[0].size(); i0++) {
    for (size_t i1 = 0; i1 <= val[1].size(); i1++) {
      for (size_t i2 = 0; i2 <= val[2].size(); i2++) {
	for (size_t i3 = 0; i3 <= val[3].size(); i3++) {
	  ll curW = i0 * w0 + i1 * (w0+1) + i2 * (w0+2) + i3 * (w0+3);
	  if (curW > W) continue;
	  ll total = acc[0][i0] + acc[1][i1] + acc[2][i2] + acc[3][i3];
	  answer = max(answer, total);
	}
      }
    }
  }
  cout << answer << endl;

  return 0;
}

