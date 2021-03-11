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

bool isdigit(char c) { return '0' <= c && c <= '9'; }

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string s1, s2; cin >> s1 >> s2;
  UnionFind uf(26);
  vector<ll> fixed;
  vector<bool> appeared(26);
  ll nonZero = -1;
  for (ll i = 0; i < N; i++) {
    char c1 = s1.at(i);
    char c2 = s2.at(i);
    if (isdigit(c2)) swap(c1, c2);
    if (isdigit(c1) && isdigit(c2)) continue;
    if (isdigit(c1)) {
      fixed.push_back(c2 - 'A');
      appeared.at(c2 - 'A') = true;
    }else {
      uf.merge(c1 - 'A', c2 - 'A');
      if (i == 0) nonZero = c1 - 'A';
      appeared.at(c1 - 'A') = true;
      appeared.at(c2 - 'A') = true;
    }
  }
  vector<bool> grp(26);
  for (ll i = 0; i < 26; i++) {
    if (!appeared.at(i)) continue;
    grp.at(uf.leader(i)) = true;
  }
  for (ll f : fixed) grp.at(uf.leader(f)) = false;
  ll tot = 1;
  for (ll i = 0; i < 26; i++) {
    if (grp.at(i)) {
      tot *= (nonZero >= 0 && i == uf.leader(nonZero)) ? 9 : 10;
    }
  }
  cout << tot << endl;

  return 0;
}

