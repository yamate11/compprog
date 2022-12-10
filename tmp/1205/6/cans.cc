#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(input UnionFind)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, S; cin >> N >> M >> S; S--;
  // @InpNbrList(N, M, nbr, dec=1) [KIJClPVp]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [KIJClPVp]
  vector<bool> ans(N);
  UnionFind uf(N);
  REPrev(nd, N - 1, 0) {
    for (ll i : nbr[nd]) {
      if (i >= nd) uf.merge(nd, i);
    }
    if (uf.leader(S) == uf.leader(nd)) ans[nd] = true;
  }
  REP(i, 0, N) if (ans[i]) cout << i + 1 << "\n";

  return 0;
}

