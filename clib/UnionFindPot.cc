#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  UnionFind with Potentials

  Usage:
    UnionFind<T> uf(N);   // Elements are 0, 1, ..., N-1.   
                          // Potentials are calculated in (T, T(0), plus<T>(), negate<T>())
    ld = uf.merge(i, j, p);   // Merges with potential(i) = potential(j) + p.  
                              //   Returns the leader if p is consistent, otherwise -1 is returned.
    ld = uf.merge(i, j);   // p == (T)0 if omitted.
    ld = uf.leader(i);     // leader
    auto [ld, p] = uf.pot(i);   // ld is the leader of i and potential(i) == potential(ld) + p

    // Before the following operation after modification, the results are calculated with O(N \alpha(N))
    n = uf.groupSize(i);   // the size of the group that i belongs to
    for (int n: uf.group(i)) {..}   // loop over the group that i belongs to

  Example.  Using XOR for potential operation
    struct Fp2 {
      int v;
      Fp2(int v_ = 0) : v(v_) {}
      Fp2 operator +(const Fp2& o) const { return Fp2(v ^ o.v); }
      Fp2 operator -() const { return Fp2(v); }
      Fp2 operator -(const Fp2& o) const { return Fp2(v ^ o.v); }
      bool operator ==(const Fp2& o) const { return v == o.v; }
      bool operator !=(const Fp2& o) const { return v != o.v; }
    };
    UnionFind<Fp2> uf(N);
    ...

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()

template<typename T = int>
struct UnionFind {
  int size;
  bool built;
  vector<pair<int, T>> _leader;
  vector<int> _gsize;
  unordered_map<int, vector<int>> _groups;
  
  UnionFind(int size_) : size(size_), built(false), _leader(), _gsize(size, 1) {
    for (int i = 0; i < size; i++) _leader.emplace_back(i, (T)0);
  }

  int merge(int i, int j, const T& p = (T)0) {
    built = false;
    auto [li, pi] = pot(i);
    auto [lj, pj] = pot(j);
    if (li == lj) {
      if (p + pj == pi) return li;
      else return -1;
    }
    int new_leader;
    if (_gsize[li] < _gsize[lj]) {
      new_leader = lj;
      _gsize[new_leader] += _gsize[li];
      _leader[li].first = new_leader;
      _leader[li].second = p + pj - pi;
    }else {
      new_leader = li;
      _gsize[new_leader] += _gsize[lj];
      _leader[lj].first = new_leader;
      _leader[lj].second = - (p + pj - pi);
    }
    return new_leader;
  }

  pair<int, T> pot(int i) {
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
    T pp = (T)0;
    while (not seen.empty()) {
      auto [j, p] = seen.back(); seen.pop_back();
      pp = pp + p;
      _leader[j] = {cur, pp};
    }
    return {cur, pp};
  }

  int leader(int i) { return pot(i).first; }

  int groupSize(int i) { return _gsize[leader(i)]; }

  unordered_map<int, vector<int>>& groups() {
    if (not built) {
      for (int i = 0; i < size; i++) _groups[i].resize(0);
      for (int i = 0; i < size; i++) _groups[leader(i)].push_back(i);
      built = true;
    }
    return _groups;
  }

  const vector<int>& group(int i) { return groups()[leader(i)]; }

};

// @@ !! END ---- UnionFind.cc

