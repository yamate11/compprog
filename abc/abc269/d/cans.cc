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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

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

  ll N; cin >> N;
  // @InpMVec(N, (X, Y)) [kvictc7v]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [kvictc7v]
  /*
  auto enc = [&](ll x, ll y) -> ll { return (x + 1100) * 2200 + (y + 1100); };
  auto dec = [&](ll e) -> pll {
    ll xx = e / 2200;
    ll yy = e % 2200;
    return pll(xx - 1100, yy - 1100);
  };
  */
  /*
  map<ll, ll> mp;
  REP(i, 0, N) { mp[enc(X[i], Y[i])] = i; }
  */
  vector rec(2200, vector(2200, -1));
  auto getrec = [&](ll x, ll y) -> ll { return rec[x + 1100][y + 1100]; };
  auto setrec = [&](ll x, ll y, ll val) -> void { rec[x + 1100][y + 1100] = val; };

  REP(i, 0, N) { setrec(X[i], Y[i], i); }
  UnionFind uf(N);
  REP(i, 0, N) {
    ll x = X[i], y = Y[i];
    auto op = [&](ll dx, ll dy) -> void {
      ll j = getrec(x + dx, y + dy);
      if (j >= 0) uf.merge(i, j);
    };
    op(-1, -1);
    op(-1, 0);
    op(0, -1);
    op(0, 1);
    op(1, 0);
    op(1, 1);
  }
  ll cnt = 0;
  REP(i, 0, N) if (uf.leader(i) == i) cnt++;
  cout << cnt << endl;
  

  return 0;
}

