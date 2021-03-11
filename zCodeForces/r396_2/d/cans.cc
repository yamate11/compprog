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

  ll n, m, q; cin >> n >> m >> q;
  map<string, ll> mp;
  vector<ll> opp(n, -1LL);
  for (ll i = 0; i < n; i++) {
    string s; cin >> s;
    mp[s] = i;
  }
  UnionFind uf(n);
  for (ll i = 0; i < m; i++) {
    ll t; cin >> t;
    string s1, s2; cin >> s1 >> s2;
    ll x1 = uf.leader(mp[s1]);
    ll x2 = uf.leader(mp[s2]);
    if (opp[x1] < 0) swap(x1, x2);
    ll y1 = opp[x1];
    ll y2 = opp[x2];
    if (t == 1) {
      if (x1 == x2) {
      }else if (y1 < 0) {
	uf.merge(x1, x2);
      }else if (y1 == x2) {
	cout << "NO\n";
	continue;
      }else if (y2 < 0) {
	ll x3 = uf.merge(x1, x2);
	opp[x3] = y1;
	opp[y1] = x3;
      }else {
	ll x3 = uf.merge(x1, x2);
	ll y3 = uf.merge(y1, y2);
	opp[x3] = y3;
	opp[y3] = x3;
      }
    }else if (t == 2) {
      if (x1 == x2) {
	cout << "NO\n";
	continue;
      }else if (y1 < 0) {
	opp[x1] = x2;
	opp[x2] = x1;
      }else if (y2 < 0) {
	ll z = uf.merge(y1, x2);
	opp[x1] = z;
	opp[z] = x1;
      }else {
	ll za = uf.merge(y1, x2);
	ll zb = uf.merge(x1, y2);
	opp[za] = zb;
	opp[zb] = za;
      }
    }
    cout << "YES\n";
  }
  for (ll i = 0; i < q; i++) {
    string s1, s2; cin >> s1 >> s2;
    ll x1 = uf.leader(mp[s1]);
    ll x2 = uf.leader(mp[s2]);
    if (x1 == x2) {
      cout << 1 << "\n";
    }else if (x2 == opp[x1]) {
      cout << 2 << "\n";
    }else {
      cout << 3 << "\n";
    }
  }


  return 0;
}

