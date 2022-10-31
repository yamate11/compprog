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

  using PQ = priority_queue<pll>;

  auto solve = [&]() -> void {
    ll N, M, Q; cin >> N >> M >> Q;
    // @InpMVec(M, ((U, dec=1), (V, dec=1))) [3Lz2Glle]
    auto U = vector(M, ll());
    auto V = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; U[i] = v1;
      ll v2; cin >> v2; v2 -= 1; V[i] = v2;
    }
    // @End [3Lz2Glle]
    vector<ll> ans(Q);
    vector rec(N, map<ll, pair<ll, PQ>>);  // rec[leader] = {left1: (right1, {(r1,q1), .. }), left2: ...}
    ll big = 1e18;
    REP(i, 0, N) {
      rec[i][-big] = {-big, PQ()};
      rec[i][i] = {i + 1, PQ()};
      rec[i][big] = {big, PQ()};
    }
    REP(q, 0, Q) {
      ll l, r; cin >> l >> r; l--;
      if (l + 1 == r) ans[q] = 0;
      else rec[l][l].second.emplace(r, q);
    }
    UnionFind uf(N);
    REP(i, 0, M) {
      ll u = uf.leader(U[i]);
      ll v = uf.leader(V[i]);
      if (u == v) continue;
      ll newLead = uf.merge(u, v);
      bool b = rec[u].size() < rec[v].size();
      auto& mu = b ? rec[u] : rec[v];
      auto& mv = b ? rec[v] : rec[u];
      for (auto& [l0, p0] : mu) {
        auto itH = mv.lower_bound(l0);
        auto itL = prev(itH);
        auto [lH, pH] = *itH;
        auto [lL, pL] = *itL;
        auto [r0, s0] = p0;
        auto [rH, sH] = pH;
        auto [rL, sL] = pL;
        if (rL == l0) {
          while (not sL.empty()) {
            auto [r, q] = sL.top();
            if (r <= r0) {
              ans[q] = i + 1;
              sL.pop();
            }else break;
          }
          bool bb = sL.size() > s0.size();
          auto& sDest = bb ? sL : s0;
          auto& sSrc  = bb ? s0 : sL;
          while (not sSrc.empty()) {
            auto [r, q] = sSrc.top(); sSrc.pop();
            sDest.emplace(r, q);
          }
          if (not bb) itL->second = {rL, sDest};
        }
        if (r0 == lH) {
          while (not s0.empty()) {
            auto [r, q] = s0.top();
            if (r <= rH) {
              ans[q] = i + 1;
              s0.pop();
            }else break;
          }
          bool bb = s0.size() > sH.size();
          auto& sDest = bb ? s0 : sH;
          auto& sSrc  = bb ? sH : s0;
          while (not sSrc.empty()) {
            auto [r, q] = sSrc.top(); sSrc.pop();
            sDest.emplace(r, q);
          }
          if (bb)

        }
        
      }


      
      rec[newLead] = ?;
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

