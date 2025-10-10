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

// @@ !! LIM()

struct StringSpec {
  using target = string;
  const int from;
  const int to;
  const int _width;
  StringSpec(int from_, int to_) : from(from_), to(to_), _width(to - from + 1) {}
  int conv(const target& s, int dep) const { return dep == (int)s.size() ? -1 : s[dep] - from; }
  int width() const { return _width; }
  target restore_init() const { return string(); }
  void restore_succ(target& s, int dep, int c) const { s += char(from + c); }
};

template <int bundle=4>
struct LLSpec {
  using target = ll;
  const ll vmin;
  const ll vmax;
  const ll dep_ub;  // the least upper bound of depth
  LLSpec(ll vmin_, ll vmax_) : vmin(vmin_), vmax(vmax_) {
    int bits = 64 - __builtin_clzll(vmax - vmin);
    dep_ub = (bits + bundle - 1) / bundle;
  }
  int conv(target x, int dep) const { return dep == dep_ub ? -1 : (x - vmin) >> (bundle * (dep_ub - 1 - dep)) & ((1LL << bundle) - 1); }
  constexpr int width() const { return (1LL << bundle); }
  target restore_init() const { return vmin; }
  void restore_succ(target& x, int dep, int c) { x += (c << (bundle * (dep_ub - 1 - dep))); }
};

template <typename Spec>
struct Trie {
  using T = typename Spec::target;

  struct Node {
    int ns; // number of elements stored in the subtree
    int nt; // number of elements stored in this node
    vector<pair<int, int>> s1; // successors.  vector of (character, index).  (terminate, 0) may be included.
    vector<int> s2; // successors.  s2[character] is the index (or -1 if not exists).  s2[terminate] := s2[0] == 0 if exists.
    Node() : ns(0), nt(0) {}
    int index(int c) {
      assert(c >= 0);
      if (s2.size() > 0) return s2[c];
      for (auto [cc, idx] : s1) if (cc == c) return idx;
      return -1;
    }
    void set_index(int c, int to_idx, int wd) {
      if (s2.size() > 0) s2[c] = to_idx;
      else if (int m = s1.size(); m < 4) {
        s1.resize(m + 1);
        int i;
        for (i = m - 1; i >= 0; i--) {
          if (c > s1[i].first) break;
          s1[i + 1] = move(s1[i]);
        }
        s1[i + 1] = {c, to_idx};
      }else {
        s2 = vector<int>(wd, -1);
        for (auto [cc, idx] : s1) s2[cc] = idx;
        s2[c] = to_idx;
        s1.resize(0);
      }
    }
    int num_lt(int c) {
      if (s2.size() > 0) {
        int s = 0;
        for (int i = 0; i < c; i++) if (s2[i] >= 0) s += body[s2[i]].ns;
        return s;
      }else {
        int s = 0;
        for (auto [cc, idx] : s1) if (cc < c) s += body[idx].ns;
        return s;
      }
    }
    pair<int, int> _nth(const auto& vec, int n) {
      int k = 0;
      if (nt > n) return {-1, k};
      k += nt;
      if (s2.size() > 0) {
        for (int i = 0; true; i++) {
          assert(i < (int)s2.size());
          int z = vec[s2[i]].ns;
          if (k + z > n) return {s2[i], k};
          else k += z;
        }
      }else {
        for (auto [cc, idx] : s1) {
          int z = vec[idx].ns;
          if (k + z > n) return {idx, k};
          else k += z;
        }
        assert(0);
      }
    }
  };

  Spec spec;
  vector<Node> body;

  Trie(Spec spec_) : spec(spec_), body(1) {}

  int size() { return body[0].ns; }

  int _find(T x, bool create, int diff = 0) {
    if (not create and diff != 0) throw domain_error("_find: not create and nonzero diff");
    int idx = 0;
    for (int dep = 0; true; dep++) {
      body[idx].ns += diff;
      int c = spec.conv(x, dep);
      if (c < 0) {
        body[idx].nt += diff;
        return idx;
      }
      int new_idx = body[idx].index(c);
      if (new_idx < 0) {
        if (not create) return -1;
        new_idx = body.size();
        body.resize(new_idx + 1);
        body[idx].set_index(c, new_idx, spec.width());
      }
      idx = new_idx;
    }
  }

  void add(T x) { _find(x, true, 1); }
  void rem(T x) { _find(x, true, -1); }
  void add_if_not_exists(T x) {
    int idx = _find(x, false);
    if (idx < 0 or body[idx].nt == 0) _find(x, true, 1);
  }
  void rem_if_exists(T x) {
    int idx = _find(x, false);
    if (idx >= 0 and body[idx].nt > 0) _find(x, true, -1);
  }
  void rem_all(T x) {
    int idx = _find(x, false);
    if (idx >= 0 and body[idx].nt > 0) _find(x, true, -body[idx].nt);
  }

  int count(T x) {
    int idx = _find(x, false);
    if (idx < 0) return 0;
    return body[idx].nt;
  }

  int _count_le_lt(T x, bool le) {
    int ret = 0;
    int idx = 0;
    for (int dep = 0; true; dep++) {
      int c = spec.conv(x, dep);
      if (c < 0) {
        if (le) ret += body[idx].nt;
        return ret;
      }
      ret += body[idx].num_lt(c);
      int new_idx = body[idx].index(c);
      if (new_idx < 0) return ret;
      idx = new_idx;
    }
  }

  int count_le(T x) { return _count_le_lt(x, true); }
  int count_lt(T x) { return _count_le_lt(x, false); }

  T nth(int n) {  // n .. 0-indexed;  n < size() should be satisfied
    if (n >= body[0].ns) throw domain_error("nth: argument should be smaller than the size");
    T ret = spec.restore_init();
    int idx = 0;
    for (int dep = 0; true; dep++) {
      auto [new_idx, k] = body[idx]._nth(body, n);
      if (new_idx < 0) return ret;
      n -= k;
      idx = new_idx;
    }
  }

  optional<T> lower_bound(T x) {
    int cnt = count_lt(x);
    if (cnt == size()) return nullopt;
    return nth(cnt);
  }

  optional<T> upper_bound(T x) {
    int cnt = count_le(x);
    if (cnt == size()) return nullopt;
    return nth(cnt);
  }
  
};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  Trie tr(StringSpec('a', 'c'));
  tr.add("abca");
  tr.add("abbbcccaaa");
  tr.add("abacc");
  tr.add("a");
  tr.add("abca");
  tr.rem("abbbcccaaa");
  // Here, tr holds "a", "abacc", "abca" * 2.
  assert(tr.count("abca") == 2);
  assert(tr.count("abbbcccaaa") == 0);
  assert(tr.count("cba") == 0);
  assert(tr.count_lt("abca") == 2);
  assert(tr.count_le("abca") == 4);
  assert(tr.nth(0) == "a");
  assert(tr.nth(2) == "abca");
  assert(tr.nth(3) == "abca");
  assert(tr.lower_bound("abacc") == "abacc");
  assert(tr.lower_bound("ab") == "abacc");
  assert(tr.upper_bound("abacc") == "abca");

  return 0;
}

