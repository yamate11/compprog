#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(input UnionFind)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted library file UnionFind.cc

template<typename T = ll, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {
  int size;
  T zero;
  oplus_t oplus;
  onegate_t onegate;
  vector<pair<int, optional<T>>> _leader;
  vector<int> _gsize;
  bool built_groups;
  int _num_groups;
  vector<vector<int>> _groups;
  
  UnionFind(int size_, T zero_ = (T)0, oplus_t oplus_ = plus<T>(), onegate_t onegate_ = negate<T>())
    : size(size_), zero(zero_), oplus(oplus_), onegate(onegate_), _gsize(size, 1), built_groups(false) {
    for (int i = 0; i < size; i++) _leader.emplace_back(i, zero);
  }

  int merge(int i, int j, optional<T> p = nullopt) {
    built_groups = false;
    auto [li, pi] = leaderpot(i);
    auto [lj, pj] = leaderpot(j);
    if (li == lj) {
      if (not p.has_value()) _leader[li].second = nullopt;
      else if (pi.has_value() and oplus(*p, *pj) != *pi) _leader[li].second = nullopt;
      return li;
    }
    int new_leader, obs_leader; bool chg_sign;
    if (_gsize[li] < _gsize[lj]) {
      new_leader = lj;
      obs_leader = li;
      chg_sign = false;
    }else {
      new_leader = li;
      obs_leader = lj;
      chg_sign = true;
    }
    _gsize[new_leader] += _gsize[obs_leader];
    _leader[obs_leader].first = new_leader;
    if (p.has_value() and pi.has_value() and pj.has_value()) {
      T new_pot = oplus(*p, oplus(*pj, onegate(*pi)));
      if (chg_sign) new_pot = onegate(new_pot);
      _leader[obs_leader].second = new_pot;
    }else {
      _leader[new_leader].second = nullopt;  // Note this is for new_leader
    }
    return new_leader;
  }

  pair<int, optional<T>> leaderpot(int i) {
    int cur = i;
    vector<pair<int, optional<T>>> seen;
    optional<T> pp;
    {
      auto [nxt, p] = _leader[cur];
      while (cur != nxt) {
        seen.emplace_back(cur, p);
        cur = nxt;
        tie(nxt, p) = _leader[cur];
      }
      pp = p;
    }
    while (not seen.empty()) {
      auto [j, p] = seen.back(); seen.pop_back();
      if (pp.has_value()) pp = oplus(pp.value(), p.value());
      _leader[j] = {cur, pp};
    }
    return {cur, pp};
  }

  int leader(int i) { return leaderpot(i).first; }
  optional<T> pot(int i) { return leaderpot(i).second; }

  int groupSize(int i) { return _gsize[leader(i)]; }

  void build_groups() {
    if (not built_groups) {
      _num_groups = 0;
      for (int j = 0; j < size; j++) if (leader(j) == j) _num_groups++;
      _groups.resize(size);
      for (int j = 0; j < size; j++) _groups[j].resize(0);
      for (int j = 0; j < size; j++) _groups[leader(j)].push_back(j);
      built_groups = true;
    }
  }

  int numGroups() {
    build_groups();
    return _num_groups;
  }

  const vector<int>& group(int i) {
    build_groups();
    return _groups[leader(i)];
  }

};

template<typename T = ll>
auto makeUnionFind(int size, T zero, auto oplus, auto onegate) {
  return UnionFind<T, decltype(oplus), decltype(onegate)>(size, zero, oplus, onegate);
}

// ---- end UnionFind.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto judge = [&]() -> bool {
    ll N, M; cin >> N >> M;
    // @InpNbrList(N, M, nbr, dec=1) [dzH3jykE]
    auto nbr = vector(N, vector(0, int()));
    for (int i = 0; i < M; i++) {
      int u, v; cin >> u >> v; u -= 1; v -= 1;
      nbr[u].emplace_back(v);
      nbr[v].emplace_back(u);
    }
    // @End [dzH3jykE]

    if (M != N - 1) return false;
    ll one = 0;
    ll two = 0;
    ll one1 = -1;
    ll one2 = -1;
    REP(i, 0, N) {
      ll a = ssize(nbr[i]);
      if (a == 1) {
        one++;
        if (one1 < 0) one1 = i;
        else one2 = i;
      }else if (a == 2) {
        two++;
      }else {
        return false;
      }
    }
    if (not (one == 2 and one + two == N)) return false;
    UnionFind uf(N);
    REP(i, 0, N) {
      for (ll j : nbr[i]) uf.merge(i, j);
    }
    ll cnt = 0;
    REP(i, 0, N) if (uf.leader(i) == i) cnt++;
    return cnt == 1;
  };

  cout << (judge() ? "Yes\n" : "No\n");

  return 0;
}

