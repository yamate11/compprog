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

class UnionFind {
protected:
  int size;
  vector<int> _leader;
  vector<int> _rank;
  
public:
  UnionFind(int s);
  int leader(int i);
  int merge(int i, int j);
};

UnionFind::UnionFind(int s) {
  size = s;
  _leader = vector<int>(size);
  for (int i = 0; i < size; i++) { _leader.at(i) = i; }
  _rank = vector<int>(size, 1);
}

int UnionFind::leader(int i) {
  int cur = i;
  int nxt = _leader.at(cur);
  vector<int> seen;
  while (cur != nxt) {
    seen.push_back(cur);
    cur = nxt;
    nxt = _leader.at(cur);
  }
  for (auto j : seen) _leader.at(j) = cur;
  return cur;
}

int UnionFind::merge(int i0, int j0) {
  int li = leader(i0);
  int lj = leader(j0);
  if (li == lj) return li;
  int ri = _rank.at(li);
  int rj = _rank.at(lj);
  if      (ri < rj)  return _leader.at(li) = lj;
  else if (ri > rj)  return _leader.at(lj) = li;
  else {
    (_rank.at(lj))++;
    return _leader.at(li) = lj;
  }
}

ll N;
// vector<ll> x;
// vector<ll> y;
constexpr ll maxXY = 1e5 + 1;
vector<vector<ll>> ysForX(maxXY);
vector<vector<ll>> xsForY(maxXY);
vector<set<ll>> yset(maxXY);
vector<ll> grpSize(maxXY);

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N;
  // x.resize(N);
  // y.resize(N);
  for (ll i = 0; i < N; i++) {
    ll xx, yy;
    cin >> xx >> yy;
    // x.at(i) = xx;
    // y.at(i) = yy;
    ysForX.at(xx).push_back(yy);
    xsForY.at(yy).push_back(xx);
  }
  UnionFind uf(maxXY);
  for (ll y = 1; y < maxXY; y++) {
    auto xs = xsForY.at(y);
    if (xs.size() <= 1) continue;
    for (size_t i = 1; i < xs.size(); i++) {
      uf.merge(xs.at(0), xs.at(i));
    }
  }
  for (ll x = 0; x < maxXY; x++) {
    ll ld = uf.leader(x);
    grpSize.at(ld) ++;
    for (ll y : ysForX.at(x)) {
      yset.at(ld).insert(y);
    }
  }
  ll numP = 0;
  for (ll x = 1; x < maxXY; x++) {
    if (uf.leader(x) != x) continue;
    numP += yset.at(x).size() * grpSize.at(x);
  }
  cout << numP - N << endl;

  return 0;
}

