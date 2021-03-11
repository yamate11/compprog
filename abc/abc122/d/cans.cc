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

ll mPrime = int(1e9) + 7;
ll N;
vector<ll> tbl0(64);

inline int enc(int j1, int j2, int j3) { return 16*j1 + 4*j2 + j3; }

void mAdd(ll& x, ll y) {
  x = (x + y) % mPrime;
}

const int iA = 0;
const int iG = 1;
const int iC = 2;
const int iT = 3;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  vector<ll> src(tbl0);
  vector<ll> dest(tbl0);
  dest.at(enc(iT,iT,iT)) = 1;

  for (int i = 0; i < N; i++) {
    src = dest;
    dest = tbl0;

    for (int j1 = 0; j1 < 4; j1++) {
      for (int j2 = 0; j2 < 4; j2++) {
	for (int j3 = 0; j3 < 4; j3++) {
	  for (int j4 = 0; j4 < 4; j4++) {
	    if (j2 == iA && j3 == iG && j4 == iC) continue;
	    if (j2 == iA && j3 == iC && j4 == iG) continue;
	    if (j2 == iG && j3 == iA && j4 == iC) continue;
	    if (j1 == iA && j2 == iG && j4 == iC) continue;
	    if (j1 == iA && j3 == iG && j4 == iC) continue;
	    mAdd(dest.at(enc(j2,j3,j4)), src.at(enc(j1,j2,j3)));
	  }
	}
      }
    }
  }
  ll ans = 0;
  for (int j1 = 0; j1 < 4; j1++) {
    for (int j2 = 0; j2 < 4; j2++) {
      for (int j3 = 0; j3 < 4; j3++) {
	mAdd(ans, dest.at(enc(j1,j2,j3)));
      }
    }
  }
  cout << ans << endl;
  return 0;
}

