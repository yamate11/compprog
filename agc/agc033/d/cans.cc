#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 1

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

ll H, W;
vector<string> A(185);
vector<vector<vector<vector<unsigned char>>>> tblY(18);


ll find() {
  for (ll c = 1; true; c++) {
    for (ll x1 = 0; x1 < W; x1++) {
      auto& prev = tblY.at(c-1).at(x1);
      for (ll y1 = 0; y1 < H; y1++) {
	auto& cur = tblY.at(c).at(x1).at(y1);
	ll y2 = y1 + 1;
	for ( ; y2 <= H; y2++) {
	  ll xc = prev.at(y1).at(y2);
	  DLOG("y1 = %lld, y2 = %lld, xc = %lld\n", y1, y2, xc);
	  if (xc == x1)  break;
	  if (xc == W)  cur.at(y2) = W;
	  else          cur.at(y2) = tblY.at(c-1).at(xc).at(y1).at(y2);
	  DLOG("a[%lld,%lld,%lld,%lld] --> %lld\n", c, x1, y1, y2, (ll)cur.at(y2));
	}
	ll yA = y2 - 1;
	ll m = prev.at(y1).at(yA);
	for ( ; y2 <= H; y2++) {
	  ll xc = prev.at(yA).at(y2);
	  if (xc == x1)  break;
	  cur.at(y2) = m <= xc ? m : xc;
	  DLOG("b[%lld,%lld,%lld,%lld] --> %lld\n", c, x1, y1, y2, (ll)cur.at(y2));
	}
	for ( ; y2 <= H; y2++)  {
	  cur.at(y2) = x1;
	  DLOG("c[%lld,%lld,%lld,%lld] --> %lld\n", c, x1, y1, y2, (ll)cur.at(y2));
	}
	if (x1 == 0 && y1 == 0 && cur.at(H) == W)  return c;
      }
    }
  }
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> H >> W;
  for (ll j = 0; j < H; j++)  cin >> A.at(j);

  for (ll c = 0; c < 18; c++) {
    tblY.at(c).resize(W);
    for (ll x = 0; x < W; x++) {
      tblY.at(c).at(x).resize(H);
      for (ll y = 0; y < H; y++) tblY.at(c).at(x).at(y).resize(H+1);
    }
  }

  for (ll y1 = 0; y1 < H; y1++)  {
    ll xFar = W;
    ll colCur = 'a';
    for (ll x1 = W-1; x1 >= 0; x1--) {
      ll colHere = A.at(y1).at(x1);
      if (colCur != colHere) {
	xFar = x1 + 1;
	colCur = colHere;
      }
      tblY.at(0).at(x1).at(y1).at(y1+1) = xFar;
      DLOG("tblY[0,%lld,%lld,%lld] = %lld\n", x1, y1, y1+1, xFar);
    }
  }

  for (ll x1 = 0; x1 < W; x1++) {
    auto& cur = tblY.at(0).at(x1);
    for (ll y1 = 0; y1 < H; y1++)  {
      ll m = cur.at(y1).at(y1+1);
      ll y2 = y1 + 1;
      for ( ; y2 < H; y2++) {
	if (A.at(y1).at(x1) != A.at(y2).at(x1))  break;
	// tblY.at(0).at(x1).at(y1).at(y2+1) = m = min(m, cur.at(y2).at(y2+1));
	cur.at(y1).at(y2+1) = m
	  = m < cur.at(y2).at(y2+1) ? m : cur.at(y2).at(y2+1);
	DLOG("tblY[0,%lld,%lld,%lld] = %lld\n", x1, y1, y2+1, m);
      }
      for ( ; y2 < H; y2++)  {
	cur.at(y1).at(y2+1) = x1;
	DLOG("tblY[0,%lld,%lld,%lld] = %lld\n", x1, y1, y2+1, x1);
      }
    }
  }

  ll answer = find();
  cout << answer << endl;
  return 0;

}

