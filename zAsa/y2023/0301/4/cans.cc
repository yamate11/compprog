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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(UnionFind)

// ---- inserted library file UnionFind.cc

template<typename T = ll, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {
  int size;
  T zero;
  oplus_t oplus;
  onegate_t onegate;
  vector<pair<int, T>> _leader;
  vector<int> _gsize;
  bool built_groups;
  vector<vector<int>> _groups;
  bool built_grouppots;
  vector<map<T, vector<int>>> _grouppots;
  
  
  UnionFind(int size_, T zero_ = (T)0, oplus_t oplus_ = plus<T>(), onegate_t onegate_ = negate<T>())
    : size(size_), zero(zero_), oplus(oplus_), onegate(onegate_), _gsize(size, 1),
      built_groups(false), built_grouppots(false) {
    for (int i = 0; i < size; i++) _leader.emplace_back(i, (T)0);
  }

  int merge(int i, int j, const T& p = (T)0) {
    built_groups = built_grouppots = false;
    auto [li, pi] = leaderpot(i);
    auto [lj, pj] = leaderpot(j);
    if (li == lj) {
      if (oplus(p, pj) == pi) return li;
      else return -1;
    }
    int new_leader;
    if (_gsize[li] < _gsize[lj]) {
      new_leader = lj;
      _gsize[new_leader] += _gsize[li];
      _leader[li].first = new_leader;
      _leader[li].second = oplus(p, oplus(pj, onegate(pi)));
    }else {
      new_leader = li;
      _gsize[new_leader] += _gsize[lj];
      _leader[lj].first = new_leader;
      _leader[lj].second = onegate(oplus(p, oplus(pj, onegate(pi))));
    }
    return new_leader;
  }

  pair<int, T> leaderpot(int i) {
    int cur = i;
    vector<pair<int, T>> seen;
    {
      auto [nxt, p] = _leader[cur];
      while (cur != nxt) {
        seen.emplace_back(cur, p);
        cur = nxt;
        tie(nxt, p) = _leader[cur];
      }
    }
    T pp = zero;
    while (not seen.empty()) {
      auto [j, p] = seen.back(); seen.pop_back();
      pp = oplus(pp, p);
      _leader[j] = {cur, pp};
    }
    return {cur, pp};
  }

  int leader(int i) { return leaderpot(i).first; }
  int pot(int i) { return leaderpot(i).second; }

  int groupSize(int i) { return _gsize[leader(i)]; }

  const vector<int>& group(int i) {
    if (not built_groups) {
      _groups.resize(size);
      for (int j = 0; j < size; j++) _groups[j].resize(0);
      for (int j = 0; j < size; j++) _groups[leader(j)].push_back(j);
      built_groups = true;
    }
    return _groups[leader(i)];
  }

  const vector<int>& grouppot(int i, const T& p) {
    if (not built_grouppots) {
      _grouppots.resize(size);
      for (int j = 0; j < size; j++) _grouppots[j].clear();
      for (int j = 0; j < size; j++) {
        auto [ld, pp] = leaderpot(j);
        _grouppots[ld][pp].push_back(j);
      }
      built_grouppots = true;
    }
    return _grouppots[leader(i)][p];
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

  ll N, M; cin >> N >> M;
  UnionFind uf(N);
  vector<ll> nontree;
  REP(i, 0, M) {
    ll u, v; cin >> u >> v; u--; v--;
    if (uf.leader(u) == uf.leader(v)) {
      nontree.push_back(u);
    }else {
      uf.merge(u, v);
    }
  }
  vector<bool> nt(N);
  for (ll x : nontree) nt[uf.leader(x)] = true;
  ll cnt = 0;
  REP(i, 0, N) {
    if (uf.leader(i) == i and not nt[i]) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

