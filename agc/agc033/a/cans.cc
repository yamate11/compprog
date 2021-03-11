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

ll H, W;
vector<string> a(1000);
vector<vector <bool>> b(1000);
vector <ll> candY;
vector <ll> nxtCandY(0);
vector <ll> candX;
vector<ll> nxtCandX(0);

ll mycount;
bool progress;

void operate(ll y, ll x) {
  if (y < 0 || y >= H || x < 0 || x >= W)  return;
  if (b.at(y).at(x))  return;
  b.at(y).at(x) = true;
  progress = true;
  nxtCandY.push_back(y);
  nxtCandX.push_back(x);
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> H >> W;
  for (ll j = 0; j < H; j++) {
    string s;
    cin >> s;
    b.at(j).resize(1000);
    for (ll i = 0; i < W; i++) {
      if (s.at(i) == '#') {
	b.at(j).at(i) = true;
	candY.push_back(j);
	candX.push_back(i);
      }else {
	b.at(j).at(i) = false;
      }
    }
  }

  mycount = 0;
  while (1) {
    progress = false;
    for (ll t = 0; t < (ll)candY.size(); t++) {
      ll y = candY.at(t);
      ll x = candX.at(t);
      operate(y+1, x);
      operate(y-1, x);
      operate(y, x+1);
      operate(y, x-1);
    }
    if (!progress)  break;
    mycount++;
    candY = nxtCandY;
    candX = nxtCandX;
    nxtCandY.resize(0);
    nxtCandX.resize(0);
  }
  cout << mycount << endl;

  return 0;
}

