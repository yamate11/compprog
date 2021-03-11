#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(UnionFind)
// --> UnionFind
// ---- inserted library file UnionFind.cc

class UnionFind {
protected:
  int size;
  vector<int> _leader;
  vector<int> _rank;
  vector<int> _gsize;
  unordered_map<int, vector<int>> _groups;
  
public:
  UnionFind(int s);
  int leader(int i);
  int merge(int i, int j);
  int groupSize(int i);
  const unordered_map<int, vector<int>>& groups();
  const vector<int>& group(int i);
};

UnionFind::UnionFind(int s) {
  size = s;
  _leader = vector<int>(size);
  for (int i = 0; i < size; i++) { _leader.at(i) = i; }
  _rank = vector<int>(size, 1);
  _gsize = vector<int>(size, 1);
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
  if (!_groups.empty()) {
    cerr << "merge() cannot be called after group() or groups()." << endl;
    exit(1);
  }
  int li = leader(i0);
  int lj = leader(j0);
  if (li == lj) return li;
  int ri = _rank.at(li);
  int rj = _rank.at(lj);
  int rep = li;
  int other = lj;
  if      (ri <  rj) swap(rep, other);
  else if (ri == rj) _rank.at(rep)++;
  _leader.at(other) = rep;
  _gsize.at(rep) += _gsize.at(other);
  return rep;
}

int UnionFind::groupSize(int i) {
  return _gsize.at(leader(i));
}

const unordered_map<int, vector<int>>& UnionFind::groups() {
  if (_groups.empty()) {
    for (int i = 0; i < size; i++) _groups[leader(i)].push_back(i);
  }
  return _groups;  
}

const vector<int>& UnionFind::group(int i) { return groups().at(leader(i)); }



// ---- end UnionFind.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector<ll> C(N);
  vector<map<ll, ll>> mps(N);
  for (ll i = 0; i < N; i++) {
    ll c; cin >> c;
    C[i] = c;
    mps[i][c] = 1;
  }
  UnionFind uf(N);
  auto mp_merge = [&](ll x, ll y) -> void {
    for (auto [c, num] : mps[y]) mps[x][c] = mps[x][c] + mps[y][c];
    ll ld = uf.merge(x, y);
    if (ld != x) mps[y] = move(mps[x]);
  };

  for (ll _q = 0; _q < Q; _q++) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll a, b; cin >> a >> b; a--; b--;
      ll lda = uf.leader(a);
      ll ldb = uf.leader(b);
      if (lda == ldb) continue;
      if (mps[lda].size() < mps[ldb].size()) mp_merge(ldb, lda);
      else mp_merge(lda, ldb);
    }else if (tp == 2) {
      ll a, b; cin >> a >> b; a--;
      cout << mps[uf.leader(a)][b] << "\n";
    }else assert(0);
  }

  return 0;
}

