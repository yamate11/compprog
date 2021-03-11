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


typedef pair<int, int> Pair;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, K, L; cin >> N >> K >> L;
  UnionFind ufRoad(N);
  UnionFind ufRail(N);

  for (int i = 0; i < K; i++) {
    int p, q; cin >> p >> q; p--; q--;
    ufRoad.merge(p, q);
  }
  for (int i = 0; i < L; i++) {
    int r, s; cin >> r >> s; r--; s--;
    ufRail.merge(r, s);
  }
  
  map<Pair, int> mp;
  for (int i = 0; i < N; i++) {
    int rd = ufRoad.leader(i);
    int rl = ufRail.leader(i);
    mp[make_pair(rd, rl)]++;
  }
  for (int i = 0; i < N; i++) {
    int rd = ufRoad.leader(i);
    int rl = ufRail.leader(i);
    if (i > 0) cout << " ";
    cout << mp[make_pair(rd, rl)];
  }
  cout << endl;

  return 0;
}

