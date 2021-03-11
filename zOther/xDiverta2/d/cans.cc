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

ll N, gA, sA, bA, gB, sB, bB;
vector<ll> abW, abV, baW, baV;

ll ks(ll weight, auto ws, auto vs) {
  vector<ll> tbl(weight+1);
  iota(tbl.begin(), tbl.end(), 0);
  for (int idx = 0; idx < (int)ws.size(); idx++) {
    ll wt = ws.at(idx);
    ll val = vs.at(idx);
    for (int j = 0; j <= weight; j++) {
      if (j >= wt) {
	tbl.at(j) = max(tbl.at(j), tbl.at(j-wt) + val);
      }
    }
  }
  return tbl.at(weight);
}


void setWV(ll a, ll b) {
  if (a < b) {
    abW.push_back(a);
    abV.push_back(b);
  }else if (b < a) {
    baW.push_back(b);
    baV.push_back(a);
  }
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N >> gA >> sA >> bA >> gB >> sB >> bB;
  setWV(gA, gB);
  setWV(sA, sB);
  setWV(bA, bB);
  cout << ks(ks(N, abW, abV), baW, baV) << endl;
  return 0;
}

