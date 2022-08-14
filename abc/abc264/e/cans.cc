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

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, E; cin >> N >> M >> E;
  vector<ll> U(E), V(E);
  REP(i, E) { cin >> U[i] >> V[i]; U[i]--; V[i]--; }
  ll Q; cin >> Q;
  vector<ll> X(Q);
  REP(i, Q) { cin >> X[i]; X[i]--; }

  vector<bool> hasPow(N + M, false);
  vector<ll> numTown(N + M, 0LL);
  REP2(i, 0, N + M) {
    if (i < N) numTown[i] = 1;
    else hasPow[i] = true;
  }
  vector<pll> Z(E);
  REP(e, E) Z[e] = pll(Q, e);
  REP(q, Q) Z[X[q]].first = q;
  sort(ALL(Z), greater<pll>());

  UnionFind uf(N + M);
  vector<ll> ans(Q);
  
  ll cnt = 0;
  for (auto [q, e] : Z) {
    if (q == Q - 1) ans[Q - 1] = cnt;
    ll a = uf.leader(U[e]);
    ll b = uf.leader(V[e]);
    if (a != b) {
      ll nt = numTown[a] + numTown[b];
      bool hp = hasPow[a] or hasPow[b];
      if (hasPow[a] and not hasPow[b]) cnt += numTown[b];
      if (hasPow[b] and not hasPow[a]) cnt += numTown[a];
      ll c = uf.merge(a, b);
      numTown[c] = nt;
      hasPow[c] = hp;
    }
    if (0 < q and q < Q) ans[q - 1] = cnt;
  }
  REP(i, Q) cout << ans[i] << "\n";

  return 0;
}

