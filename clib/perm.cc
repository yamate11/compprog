#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Permutations

  Structs:
    IntPerm, IntComb, IntDupPerm, IntDupComb, IntDirProd

  Usage:

    IntPerm ip(3, 2);      // Sequences of length 2 from [0, 3), no duplication
    IntComb ic(3, 2);      // Sorted sequences of length 2 from [0, 3), no duplication
    IntDupPerm dip(3, 2);  // Sequences of length 2 from [0, 3)
    IntDupComb dic(3, 2);  // Sorted sequences of length 2 from [0, 3)
    IntDirProd did{vector{{1, 2, 3}}};  // Sequences (a, b, c) s.t. a < 1, b < 2 and c < 3

    while (ip.get()) {  
      for (int i = 0; i < 2; i++) cout << ip.at(i) << " ";
      // or, equivalently,
      const vector<int>& v = ip.vec_view();
      for (int i = 0; i < 2; i++) cout << v[i] << " ";
    }

    // Results:
    //    IntPerm    ...       [0,1],[0,2],[1,0],      [1,2],[2,0],[2,1]
    //    IntComb    ...       [0,1],[0,2],            [1,2]
    //    IntDupPerm ... [0,0],[0,1],[0,2],[1,0],[1,1],[1,2],[2,0],[2,1],[2,2]
    //    IntDupComb ... [0,0],[0,1],[0,2],      [1,1],[1,2],            [2,2]
    //
    //    IntDirProd ... [0,0,0],[0,0,1],[0,0,2],[0,1,0],[0,1,1],[0,1,2]

    // Note:
    //    Unless 0 <= n and 0 <= r, they returns {}.
    //    IntPerm and IntComb returns {} unless r <= n.
    //    When n = 0 and r = 0, IntDupPerm and IntDupComb returns { [] } instead of {},
    //       which may not be appropriate (since they mean 0^0 = 1 and H(n, r) != C(n+r-1, r).)
    //    When n = 0 and r != 0, all returns {}.

    // When ip.get() returns false, it's internal has gone back to the
    // init state, so you can continue the next round.

   For Debugging:
      const vector<int>& vec_view() const;
*/

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- perm.cc

template <bool dup>
struct IntPermBase {
  int n;
  int r;
  vector<int> vec;
  bool started;

  bool start_check() {
    if constexpr (dup) { if (not ((1 <= n and 0 <= r) or (n == 0 and r == 0))) return false; }
    else { if (not (0 <= n and 0 <= r and r <= n)) return false; }
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  IntPermBase(int n_, int r_) : n(n_), r(r_), started(false) {}

  int at(int i) const { return vec[i]; }

  const vector<int>& vec_view() const { return vec; }
};

struct IntPerm : IntPermBase<false> {
  vector<vector<int>> cands;
  vector<int> cidx;

  bool start_check() {
    if (not IntPermBase<false>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    cands.resize(r);
    cidx.resize(r);
    for (int i = 0; i < r; i++) {
      for (int j = n - 1; j >= i; j--) cands[i].push_back(j);
      cidx[i] = n - i - 1;
    }
    return true;
  }

  bool finish() {
    cands.resize(0);
    cidx.resize(0);
    return IntPermBase<false>::finish();
  }

  IntPerm(int n_, int r_) : IntPermBase<false>(n_, r_) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and cidx[i] == 0; i--);
    if (i < 0) return finish();
    vec[i] = cands[i][--cidx[i]];
    for (int j = i + 1; j < r; j++) {
      if (j == i + 1) {
        cands[j].resize(0);
        for (int k = 0; k < (int)cands[i].size(); k++) {
          if (k == cidx[i]) continue;
          cands[j].push_back(cands[i][k]);
        }
      }else {
        cands[j] = cands[j - 1];
        cands[j].pop_back();
      }
      cidx[j] = n - j - 1;
      vec[j] = cands[j][cidx[j]];
    }
    return true;
  }
};

struct IntComb : IntPermBase<false> {
  bool start_check() {
    if (not IntPermBase<false>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    return true;
  }

  IntComb(int n_, int r_) : IntPermBase<false>(n_, r_) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - r + i; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[j - 1] + 1;
    return true;
  }
};

struct IntDupPerm : IntPermBase<true> {
  IntDupPerm(int n_, int r_) : IntPermBase<true>(n_, r_) {}

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < n) return true;
    return finish();
  }
};

struct IntDupComb : IntPermBase<true> {
  IntDupComb(int n_, int r_) : IntPermBase<true>(n_, r_) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - 1; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[i];
    return true;
  }
};

template<typename INT>
struct IntDirProd {
  vector<INT> lim;
  int r;
  vector<INT> vec;
  bool started;

  IntDirProd(const vector<INT>& lim_) : lim(lim_), r(lim.size()), started(false) {}

  int at(int i) const { return vec[i]; }

  const vector<INT>& vec_view() const { return vec; }

  bool start_check() {
    for (int i = 0; i < r; i++) if (lim[i] == 0) return false;
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < lim[i]) return true;
    return finish();
  }

};

// @@ !! END() ---- perm.cc
