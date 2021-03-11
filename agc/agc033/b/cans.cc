#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DLOG(...)
#endif

void debug(auto f) {
#if DEBUG
  f();
#endif
}

ll H, W, N;
ll sr, sc;
string S, T;

ll dirX(char c) {
  if (c == 'L')  return -1;
  if (c == 'R')  return 1;
  return 0;
}

ll dirY(char c) {
  if (c == 'D')  return 1;
  if (c == 'U')  return -1;
  return 0;
}

bool myout(ll y, ll x)  {
  return y > H || y < 1 || x > W || x < 1;
}

bool game(char cT, char cA) {
  ll y = sr;
  ll x = sc;
  ll mvTy = dirY(cT);
  ll mvTx = dirX(cT);
  ll mvAy = dirY(cA);
  ll mvAx = dirX(cA);
  for (ll i = 0; i < N; i++) {
    if (S.at(i) == cT) {
      y += mvTy;
      x += mvTx;
      if (myout(y, x))  return true;
    }
    if (T.at(i) == cA)  {
      ll y1 = y + mvAy;
      ll x1 = x + mvAx;
      if (!myout(y1, x1)) {
	y = y1;
	x = x1;
      }
    }
  }
  return false;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> H >> W >> N >> sr >> sc >> S >> T;

  bool result = false;
  result = result || game('R', 'L');
  result = result || game('L', 'R');
  result = result || game('D', 'U');
  result = result || game('U', 'D');
  if (result) {
    cout << "NO" << endl;
  }else {
    cout << "YES" << endl;
  }

  return 0;
}

