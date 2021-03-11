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

  ll H, W; cin >> H >> W;
  vector<string> S(H);
  for (ll i = 0; i < H; i++) {
    cin >> S[i];
  }
  const ll ROW = 0;
  const ll COL = 1;
  auto enc = [&](ll x, ll tp) {
    if (tp == ROW) return x;
    else return H + x;
  };
  UnionFind uf(H + W);
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      if (S[i][j] == '#') uf.merge(enc(i, ROW), enc(j, COL));
    }
  }
  uf.merge(enc(0, ROW), enc(0, COL));
  uf.merge(enc(0, ROW), enc(W - 1, COL));
  uf.merge(enc(H - 1, ROW), enc(0, COL));

  ll n_row = 0;
  ll n_col = 0;
  vector<bool> v_row(H + W), v_col(H + W);
  for (ll i = 0; i < H; i++) {
    ll t = uf.leader(enc(i, ROW));
    if (!v_row[t]) {
      v_row[t] = true;
      n_row++;
    }
  }
  for (ll i = 0; i < W; i++) {
    ll t = uf.leader(enc(i, COL));
    if (!v_col[t]) {
      v_col[t] = true;
      n_col++;
    }
  }
  cout << min(n_row, n_col) - 1 << endl;


  return 0;
}

