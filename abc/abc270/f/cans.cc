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

// @@ !! LIM(input f:updMaxMin UnionFind forall)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

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

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = from; i < to; i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  enum { NONE, ROAD, AIR, SEA };
  const ll big = 1e18;
  
  ll N, M; cin >> N >> M;
  using data_t = tuple<ll, ll, ll, ll>; 
  vector<data_t> data;
  REP(i, 0, N) {
    ll x; cin >> x;
    data.emplace_back(x, AIR, i, -1);
  }
  REP(i, 0, N) {
    ll y; cin >> y;
    data.emplace_back(y, SEA, i, -1);
  }
  REP(i, 0, M) {
    ll a, b, z; cin >> a >> b >> z; a--; b--;
    data.emplace_back(z, ROAD, a, b);
  }
  sort(ALL(data));
  
  auto calc = [&](bool air, bool sea) -> ll {
    UnionFind uf(N);
    vector<bool> hasAir(N);
    vector<bool> hasSea(N);
    bool hasBoth = false;
    ll ret = 0;
    for (auto [cost, tp, i, j] : data) {
      if (tp == AIR) {
        if (not air) continue;
        ll p = uf.leader(i);
        if (hasAir[p]) continue;
        if (hasSea[p]) {
          if (hasBoth) continue;
          hasBoth = true;
        }
        hasAir[p] = true;
        ret += cost;
      }else if (tp == SEA) {
        if (not sea) continue;
        ll p = uf.leader(i);
        if (hasSea[p]) continue;
        if (hasAir[p]) {
          if (hasBoth) continue;
          hasBoth = true;
        }
        hasSea[p] = true;
        ret += cost;
      }else if (tp == ROAD) {
        ll p = uf.leader(i);
        ll q = uf.leader(j);
        if (p == q) continue;
        if ((hasAir[p] and hasAir[q]) or (hasSea[p] and hasSea[q])) continue;
        if ((hasAir[p] and hasSea[q]) or (hasSea[p] and hasAir[q])) {
          if (hasBoth) continue;
          hasBoth = true;
        }
        ll r = uf.merge(p, q);
        hasAir[r] = hasAir[p] or hasAir[q];
        hasSea[r] = hasSea[p] or hasSea[q];
        ret += cost;
      }
    }
    if (not air and not sea and EXISTS(i, 1, N, uf.leader(0) != uf.leader(i))) return big;
    return ret;
  };

  ll ans = calc(1, 1);
  updMin(ans, calc(0, 1));
  updMin(ans, calc(1, 0));
  updMin(ans, calc(0, 0));
  cout << ans << endl;

  return 0;
}

