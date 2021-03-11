#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> U(M), V(M);
  for (ll i = 0; i < M; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    U.at(i) = u;
    V.at(i) = v;
  }
  UnionFind uf(N);
  for (ll i = 0; i < M; i++) {
    uf.merge(U.at(i), V.at(i));
  }
  map<ll, ll> numEdges;
  map<ll, ll> numNodes;
  for (ll i = 0; i < M; i++) {
    ll l = uf.leader(U.at(i));
    numEdges[l]++;
  }
  for (ll i = 0; i < N; i++) {
    ll l = uf.leader(i);
    numNodes[l]++;
  }
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    if (uf.leader(i) != i) continue;
    if (numEdges[i] == numNodes[i] - 1) ans++;
  }
  cout << ans << endl;

  return 0;
}

