#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  UnionFind

  Usage:
    UnionFind uf(N);  // grouping {0, ..., N-1}
    uf.merge(i, j);   // put i and j in a same group
    if (uf.leader(i) == uf.leader(j)) ... 
                      // test if i and j are in a same group
    n = uf.groupSize(i) // the size of the group that i belongs to

    for (int n: uf.group(i)) ....
                      // loop over the group that i belongs to
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()

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



// @@ !! END ---- UnionFind.cc

class myRandom {
  random_device dev;
  mt19937 rng;
public:
  myRandom() : rng(dev()) {}
  void two(int n, int& k1, int& k2) {
    uniform_int_distribution<int> dist(0, n-1);
    k1 = dist(rng);
    k2 = dist(rng);
    // if (k1 == k2) two(n, k1, k2);
  }
};

void naiveCompare(int n, int repeat) {
  vector<vector<bool>> nbr(n, vector<bool>(n));
  auto naive_merge = [&](int p, int q) -> void {
    nbr.at(p).at(q) = nbr.at(q).at(p) = true;
  };
  auto naive_reachable = [&](int p, int q) -> pair<bool, int> {
    // cerr << "naive_reachable CALLED " << p << " " << q << endl;
    vector<bool> visited(n);
    bool found = false;
    ll cnt = 0;
    auto nr_sub = [&](const auto& recF, int x) -> void {
      // cerr << "nr_sub " << x << endl;
      if (visited.at(x)) return;
      visited.at(x) = true;
      cnt++;
      // cerr << "cnt " << cnt << endl;
      if (x == q) found = true;
      for (int c = 0; c < n; c++) if (nbr.at(x).at(c)) recF(recF, c);
    };
    nr_sub(nr_sub, p);
    return make_pair(found, cnt);
  };

  UnionFind uf(n);
  myRandom rand;
  for (int _rep = 0; _rep < repeat; _rep++) {
    int k1, k2; rand.two(n, k1, k2);
    uf.merge(k1, k2);
    naive_merge(k1, k2);
    // cerr << "merge " << k1 << " " << k2 << endl;
    int k3, k4; rand.two(n, k3, k4);
    bool res_naive; int gsize_naive;
    tie(res_naive, gsize_naive) = naive_reachable(k3, k4);
    bool res_uf = uf.leader(k3) == uf.leader(k4);
    int gsize_uf = uf.groupSize(k3);
    // cerr << "reachable " << k3 << " " << k4 << " " << res_uf
    //      << " " << res_naive << endl;
    assert(res_uf == res_naive);
    // cerr << "gsize " << k3 << " " << k4 << " "
    //      << gsize_uf << " " << gsize_naive << endl;
    assert(gsize_uf == gsize_naive);
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  UnionFind uf1(6);
  assert(uf1.leader(0) != uf1.leader(5));
  assert(uf1.groupSize(5) == 1);
  uf1.merge(0, 5);
  assert(uf1.leader(0) == uf1.leader(5));
  assert(uf1.groupSize(5) == 2);
  assert(uf1.groupSize(0) == 2);
  uf1.merge(1, 3);
  uf1.merge(2, 5);
  assert(uf1.groupSize(2) == 3);
  assert(uf1.leader(0) == uf1.leader(2));
  assert(uf1.leader(1) == uf1.leader(3));
  assert(uf1.leader(4) != uf1.leader(0));
  assert(uf1.leader(0) != uf1.leader(1));

  assert(uf1.group(2) == vector<int>({0, 2, 5}));
  assert(uf1.group(3) == vector<int>({1, 3}));

  for (int _z = 0; _z <= 100; _z++) naiveCompare(_z+1, 200);

  cout << "test done." << endl;
}
