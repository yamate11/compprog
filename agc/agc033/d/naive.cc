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
vector<vector<vector<vector<ll>>>> tbl;

bool same_color(ll y1, ll y2, ll x1, ll x2) {
  ll col = A.at(y1).at(x1);
  for (ll y = y1; y < y2; y++) {
    for (ll x = x1; x < x2; x++) {
      if (A.at(y).at(x) != col)  return false;
    }
  }
  return true;
}

ll calc(ll y1, ll y2, ll x1, ll x2);

ll do_calc(ll y1, ll y2, ll x1, ll x2) {
  if (same_color(y1, y2, x1, x2))  return 0;
  ll retval = 1000;
  for (ll y = y1 + 1; y < y2; y++) {
    retval = min(retval, 1 + max(calc(y1, y, x1, x2), calc(y, y2, x1, x2)));
  }
  for (ll x = x1 + 1; x < x2; x++) {
    retval = min(retval, 1 + max(calc(y1, y2, x1, x), calc(y1, y2, x, x2)));
  }
  return retval;
}

ll calc(ll y1, ll y2, ll x1, ll x2) {
  ll& cell = tbl.at(y1).at(y2).at(x1).at(x2);
  if (cell >= 0) return cell;
  cell = do_calc(y1, y2, x1, x2);
  return cell;
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> H >> W;
  for (ll j = 0; j < H; j++)  cin >> A.at(j);

  tbl.resize(H);
  for (ll y1 = 0; y1 < H; y1++) {
    tbl.at(y1).resize(H+1);
    for (ll y2 = y1+1; y2 <= H; y2++) {
      tbl.at(y1).at(y2).resize(W);
      for (ll x1 = 0; x1 < W; x1++) {
	tbl.at(y1).at(y2).at(x1).resize(W+1);
	for (ll x2 = x1+1; x2 <= W; x2++) {
	  tbl.at(y1).at(y2).at(x1).at(x2) = -1;
	}
      }
    }
  }

  ll answer = calc(0, H, 0, W);
  cout << answer << endl;

  return 0;
}
