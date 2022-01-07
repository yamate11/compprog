#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(UnionFind)

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

  ll N, M; cin >> N >> M;
  vector<vector<ll>> nbr(N);
  REP(i, M) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
  }
  UnionFind uf(N);
  ll conn = 0;
  vector<ll> ans(N);
  REP2R(i, N-1, 0) {
    conn += 1;
    for (ll x : nbr[i]) {
      if (uf.leader(x) == uf.leader(i)) {
      }else {
        conn -= 1;
        uf.merge(x, i);
      }
    }
    ans[i] = conn;
  }
  REP(i, N-1) cout << ans[i + 1] << "\n";
  cout << 0 << "\n";

  return 0;
}

