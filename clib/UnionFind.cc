#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  UnionFind with Potentials

  Usage:
    UnionFind<T> uf(N);   // Elements are 0, 1, ..., N-1.   T is defaulted to ll.
                          // Potentials are calculated in (T, (T)0, plus<T>(), negate<T>())
    ld = uf.merge(i, j, p);   // Merges with potential(i) = potential(j) + p.  
                              //   Returns the leader if p is consistent, otherwise -1 is returned.
    ld = uf.merge(i, j);   // p == (T)0 if omitted.
    ld = uf.leader(i);     // leader
    p = uf.pot(i);         // potential w.r.t i's leader
    auto [ld, p] = uf.leaderpot(i);   // ld is the leader of i and potential(i) == potential(ld) + p
    n = uf.groupSize(i);   // the size of the group that i belongs to

    // Before the following operation after modification, the results are calculated with O(N \alpha(N))
    for (int n: uf.group(i)) {..}   // loop over the group that i belongs to
    for (int n: uf.grouppot(i, p)) {..} // loop over elements in group i with potential p

  If you are to use adhoc operators:
    auto uf = makeUnionFind<T>(N, zero, plus, negate);

  Example.  Using XOR for potential operation
    // (with including ftwo.cc)
    UnionFind<Ftwo> uf(N);

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()

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

// @@ !! END ---- UnionFind.cc

