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
  // @InpMVec(M, ((A, dec=1), (B, dec=1), Y)) [6Itbql5O]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto Y = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; Y[i] = v3;
  }
  // @End [6Itbql5O]
  ll Q; cin >> Q;
  // @InpMVec(Q, ((V, dec=1), W)) [Pf54F4g6]
  auto V = vector(Q, ll());
  auto W = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; V[i] = v1;
    ll v2; cin >> v2; W[i] = v2;
  }
  // @End [Pf54F4g6]

  vector<pll> ord;
  REP(i, 0, M) ord.emplace_back(0, i);
  REP(i, 0, Q) ord.emplace_back(1, i);
  sort(ALL(ord), [&](pll p, pll q) -> bool {
    auto [tp, ip] = p;
    auto [tq, iq] = q;
    ll yp = tp == 0 ? Y[ip] : W[ip];
    ll yq = tq == 0 ? Y[iq] : W[iq];
    if (yp != yq) return yp > yq;
    if (tp != tq) return tp > tq;
    return ip < iq;
  });
  UnionFind uf(N);
  vector<ll> ans(Q);
  for (auto [t, i] : ord) {
    if (t == 0) {
      uf.merge(A[i], B[i]);
    }else if (t == 1) {
      ans[i] = uf.groupSize(V[i]);
    }
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

