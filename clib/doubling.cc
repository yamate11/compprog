#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
    See https://yamate11.github.io/blog/posts/2022/12-10-doubling/

    Doubling:
      (1) Usually, this lib is used to calculate frel^{(r)}(i) for r in [0, R] and i in [0, N).
          frel: [0, N) -> [0, N).  Typical sizes are 
            (a)  N ~ 1e5, R ~ 1e18, or
            (b)  R ~ 1e5 but the calculation is conducted repeatedly, say 1e5 times.
      (2) Occasionally, another mapping: [0, N) -> T for some monoid T is given, and
          \sum_{r = p}^{q} mapping(frel^{(r)}(i))  is to be calculated.  (sum is the monoid sum)

          If monoid operator other than `+` is needed, define a struct with overriding operator + and 
          the default constructor for the unit, say:
             struct M {
               ll v;
               M(ll v_ = LLONG_MIN) : v(v_) {}
               M operator+(const M& o) const { return M(max(v, o.v)); }
             };

    Case (1):
      DoublingFRel d(R, N, frel);  
      cout << d.val(r, i);         // frel^{(r)}(i)
                                   // for r \in [0, R] and i \in [0, n-1]
      // internal table stores frel^{(r)}(i) for r = 1, 2, 4, ..., 2^k

    Case (2):
      DoublingFRel d1(R, N, frel);
      DoublingCur<ll> d2(d1, mapping);   // NOTE: <ll> is necessary!!
      cout << d2.val(r, i);  // \sum { mapping( frel^{(j)}(i) ) | j = 0, 1, ..., r-1 }
                             // for r \in [0, R] and i \in [0, n-1] 
      // internal table stores mapping( frel^{(r)}(i) ) for r = 0, 1, 2, ..., 2^(k-1)
*/

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- doubling.cc

struct DoublingFRel { // from functional relation
  int n;
  vector<vector<int>> tbl;

  void _init(long long lim, auto frel) {
    int K = 64 - __builtin_clzll(lim);
    tbl.resize(K, vector<int>(n));
    for (int i = 0; i < n; i++) tbl[0][i] = frel(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < n; i++) tbl[k + 1][i] = tbl[k][tbl[k][i]];
  }

  DoublingFRel(long long lim, int n_, auto frel) : n(n_) { _init(lim, frel); }

  int val(long long x, int i) { // Calculates frel^{(x)}(i).  Should be x <= lim.
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) i = tbl[k][i];
    return i;
  }
};
  
template <typename T>
struct DoublingCum {
  const DoublingFRel& d;
  vector<vector<T>> tbl;

  void _init(auto mapping) {
    int K = d.tbl.size();
    tbl.resize(K, vector<T>(d.n));
    for (int i = 0; i < d.n; i++) tbl[0][i] = mapping(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < d.n; i++) tbl[k + 1][i] = tbl[k][i] + tbl[k][d.tbl[k][i]];
  }

  DoublingCum(const DoublingFRel& d_, auto mapping) : d(d_) { _init(mapping); }

  T val(long long x, int i) { // the monoid sum of x objs from i.  i.e. from i to i + x - 1.
    T ret = T();
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) {
        ret = ret + tbl[k][i];
        i = d.tbl[k][i];
      }
    return ret;
  }
};

// @@ !! END ---- doubling.cc

