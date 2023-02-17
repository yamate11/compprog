#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  UnionFind with Relation

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
// @@ !! BEGIN()  ---- UnionFindRel.cc

template<typename T, typename add_t, typename neg_t, typename mult_t, typename div_t>
struct UnionFindRel {

  using rel_t = pair<T, T>;

  int size;
  T zero;
  T one;
  add_t add;
  neg_t neg;
  mult_t mult;
  div_t div;
  vector<int> _leader;
  vector<rel_t> _rel;    
  vector<optional<T>> _v;
  // when l = _leader[i] and _v[l] is defined,  _v[i] = apply(_rel[i], _v[l])
  vector<int> _gsize;
  bool built_groups;
  vector<vector<int>> _groups;
  
  UnionFindRel(int size_, T zero_, T one_, add_t add_, neg_t neg_, mult_t mult_, div_t div_)
    : size(size_), zero(zero_), one(one_), add(add_), neg(neg_), mult(mult_), div(div_),
      _v(size), _gsize(size, 1), built_groups(false) {
    for (int i = 0; i < size; i++) {
      _leader.emplace_back(i);
      _rel.emplace_back(one, zero);
    }
  }

  rel_t comp(rel_t r2, rel_t r1) {
    auto [a, b] = r1;
    auto [c, d] = r2;
    return {mult(a, c), add(mult(b, c), d)};
  }
    
  rel_t inv(rel_t r) {
    auto [a, b] = r;
    return {div(one, a).value(), div(neg(b), a).value()};
    // This means that r.first should have the inverse.
  }

  T apply(rel_t r, T x) { return add(mult(r.first, x), r.second); }

  int merge(int i, int j, const rel_t& r) { // v_i = a * v_j + b, where r = {a, b}
    built_groups = false;
    auto [li, ri] = leader_rel(i);
    auto [lj, rj] = leader_rel(j);
    if (li == lj) {
      if (_v[li].has_value()) {
        return (_v[i].value() == _v[j].value()) ? li : -1;
      }else {
        rel_t c = comp(r, rj);
        if (ri == c) return i;
        if (ri.first == c.first) return -1;
        optional<T> x = div(add(c.second, neg(ri.second)), add(ri.first, neg(c.first)));
        if (not x.has_value()) return -1;
        _v[li] = x;
        _v[i] = apply(ri, *x);
        _v[j] = apply(rj, *x);
        return li;
      }
    }
    int new_leader, old_leader;
    
    if (_gsize[li] < _gsize[lj]) {
      new_leader = lj;
      old_leader = li;
      _rel[li] = comp(inv(ri), comp(r, rj));
    }else {
      new_leader = li;
      old_leader = lj;
      _rel[lj] = comp(inv(comp(r, rj)), ri);
    }
    _gsize[new_leader] += _gsize[old_leader];
    _leader[old_leader] = new_leader;
    if (_v[new_leader].has_value() and _v[old_leader].has_value()) {
      if (apply(_rel[old_leader], _v[new_leader].value()) != _v[old_leader].value()) return -1;
    }else if (_v[old_leader].has_value()) {
      _v[new_leader] = apply(inv(_rel[old_leader]), _v[old_leader].value());
    }
    return new_leader;
  }

  pair<int, rel_t> leader_rel(int i) {
    int cur = i;
    vector<int> seen;
    rel_t r(one, zero);
    while (true) {
      ll nxt = _leader[cur];
      if (cur == nxt) break;
      seen.push_back(cur);
      cur = nxt;
    }
    int ld = cur;
    while (not seen.empty()) {
      ll j = seen.back(); seen.pop_back();
      r = comp(_rel[j], r);
      _leader[j] = ld;
      _rel[j] = r;
    }
    return {ld, r};
  }

  int leader(int i) { return leader_rel(i).first; }
  rel_t rel(int i) { return leader_rel(i).second; }

  optional<T> get_val(int i) {
    if (_v[i].has_value()) return _v[i];
    ll ld = leader(i);
    if (_v[ld].has_value()) {
      _v[i] = apply(_rel[i], _v[ld].value());
      return _v[i];
    }
    return nullopt;
  }

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

};

template<typename T>
auto makeUnionFindRel(int size, T zero, T one, auto add, auto neg, auto mult, auto div) {
  return UnionFindRel<T, decltype(add), decltype(neg), decltype(mult), decltype(div)>
    (size, zero, one, add, neg, mult, div);
}

template<typename I>
optional<I> mydivide(I a, I b) {
  if (b == 0 or a % b != 0) return nullopt;
  return a / b;
}

// @@ !! END ---- UnionFindRel.cc

