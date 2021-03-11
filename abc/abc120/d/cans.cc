#include <bits/stdc++.h>

#define DEBUG 0

using namespace std;

void debug(string msg) {
#if DEBUG
  cerr << msg << endl;
#endif
}

  
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

class MyUnionFind : public UnionFind {
  vector<int> _gsize;
public:
  MyUnionFind(int s) : UnionFind(s) { _gsize = vector<int>(size, 1); }
  int gsize(int i) { return _gsize.at(leader(i)); }
  int merge(int i0, int j0) {
    int li = leader(i0);
    int lj = leader(j0);
    if (li == lj) return li;
    int newLeader = UnionFind::merge(li, lj);
    _gsize.at(newLeader) = _gsize.at(li) + _gsize.at(lj);
    return newLeader;
  }
};

long long combi(long long k) { return k * (k-1) / 2; }

int main() {
  debug("A");
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> a.at(i) >> b.at(i);
  }
  
  debug("B");
  MyUnionFind uf(n+1);
  vector<long long> diff(m, 0);
  for (int i = m - 1; i >= 0; i--) {
    int xa = a.at(i);
    int xb = b.at(i);
    int la = uf.leader(xa);
    int lb = uf.leader(xb);
    if (la == lb)  continue;
    long long sizePrev = combi(uf.gsize(la)) + combi(uf.gsize(lb));
    int newL = uf.merge(xa, xb);
    diff.at(i) = combi(uf.gsize(newL)) - sizePrev;
  }
  debug("C");
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    sum += diff.at(i);
    cout << sum << endl;
  }

  return 0;
}

