#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if defined(DEBUG)

#include <unistd.h>
#include <sys/fcntl.h>
#define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
#define DCALL(func, ...) func(__VA_ARGS__)

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#else  // defined(DEBUG)

#define DLOG(...)
#define DCALL(func, ...)

#endif // defined(DEBUG)

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

// ----------------------------------------------------------------------

struct DI {
  int axis;
  int idx1;
  int idx2;
  int dist;
  DI(int a, int i1, int i2, int d) : axis(a), idx1(i1), idx2(i2), dist(d) {}
  bool operator<(const DI& that) const { return dist < that.dist; }
};

int N;
vector<vector<int>> Z(2);

// dist ... list of (i, axis, dist)
//          where dist is the distance between i and the next larger point
//          in the direction of axis, sorted by dist
vector<DI> dist;


int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cout << setprecision(20);

  cin >> N;
  Z.at(0).resize(N); Z.at(1).resize(N);
  for (int i = 0; i < N; i++) cin >> Z.at(0).at(i) >> Z.at(1).at(i);
  for (int axis = 0; axis <= 1; axis++) {
    vector<int> ordZ(N);
    iota(ordZ.begin(), ordZ.end(), 0);
    sort(ordZ.begin(), ordZ.end(),
	 [&](int p, int q) { return Z.at(axis).at(p) < Z.at(axis).at(q); });
    for (int i = 0; i < N-1; i++) {
      int idx1 = ordZ.at(i);
      int idx2 = ordZ.at(i+1);
      dist.emplace_back(axis, idx1, idx2,
			Z.at(axis).at(idx2) - Z.at(axis).at(idx1));
    }
  }
  sort(dist.begin(), dist.end());
  
  int ans = 0;
  UnionFind uf(N);
  for (DI d : dist) {
    if (uf.leader(d.idx1) == uf.leader(d.idx2)) continue;
    ans += d.dist;
    uf.merge(d.idx1, d.idx2);
  }
  cout << ans << endl;

}
