#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(UnionFind)
// --> UnionFind
// ---- inserted library file UnionFind.cc

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
// ---- end UnionFind.cc
// @@ !! LIM  -- end mark --

using Tup = tuple<ll, ll, ll>;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<Tup> edges;
  for (ll i = 0; i < N; i++) {
    ll c; cin >> c;
    edges.emplace_back(c, i, N);
  }
  for (ll i = 0; i < M; i++) {
    ll a, b, r; cin >> a >> b >> r; a--; b--;
    edges.emplace_back(r, a, b);
  }
  sort(edges.begin(), edges.end());
  ll tot = 0;
  UnionFind uf(N+1);
  for (Tup t : edges) {
    ll a, b, r; tie(r, a, b) = t;
    if (uf.leader(a) == uf.leader(b)) continue;
    tot += r;
    uf.merge(a, b);
  }
  cout << tot << endl;

  return 0;
}

