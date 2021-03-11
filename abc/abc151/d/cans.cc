#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


// --- DEBUG begin --- cut here ---
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

// operator<< definitions for some classes

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}
// --- DEBUG end --- cut here ---



int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  vector<string> S(H);
  for (ll i = 0; i < H; i++) cin >> S.at(i);
  
  vector<vector<ll>> dist(H*W, vector<ll>(H*W, H*W+1));

  auto enc = [&](ll i, ll j) -> ll { return i*W + j; };
  
  auto chk = [&](ll i, ll j, ll di, ll dj) -> void {
    ll iN = i + di;
    ll jN = j + dj;
    if (!(0 <= iN && iN < H && 0 <= jN && jN < W)) return;
    if (S.at(iN).at(jN) == '#') return;
    ll e1 = enc(i, j);
    ll e2 = enc(iN, jN);
    dist.at(e1).at(e2) = 1;
    dist.at(e2).at(e1) = 1;
  };

  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      if (S.at(i).at(j) == '#') continue;
      ll e = enc(i, j);
      dist.at(e).at(e) = 0;
      chk(i, j, 1, 0);
      chk(i, j, -1, 0);
      chk(i, j, 0, 1);
      chk(i, j, 0, -1);
    }
  }

  while (true) {
    bool notyet = false;
    for (ll i = 0; i < H*W; i++) {
      for (ll j = 0; j < H*W; j++) {
	for (ll k = 0; k < H*W; k++) {
	  ll x = dist.at(i).at(k) + dist.at(k).at(j);
	  if (x < dist.at(i).at(j)) {
	    DLOG("update", i, j, k, x, dist.at(i).at(j));
	    dist.at(i).at(j) = x;
	    notyet = true;
	  }
	}
      }
    }
    if (!notyet) break;
  }

  /*
  DLOG("dist", dist);
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      cerr << dist.at(0).at(enc(i, j)) << " ";
    }
    cerr << endl;
  }
  */

  ll ans = 0;
  for (ll i = 0; i < H*W; i++) {
    for (ll j = 0; j < H*W; j++) {
      ll x = dist.at(i).at(j);
      if (x > H*W) continue;
      ans = max(ans, x);
    }
  }
  cout << ans << endl;


  return 0;
}

