/*
  fastTransform.cc

  Fast transformations:
    - Zeta transformation (upper/lower)
    - Moebius transformation (upper/lower)
    - Hadamard transformation
  and {and|or|xor} convolutions using these transformations

  Functions:

    vector<T> xor_conv(vector<T> vec1, vector<T> vec2);
    vector<T> and_conv(vector<T> vec1, vector<T> vec2);
    vector<T> or_conv(vector<T> vec1, vector<T> vec2);
      Returns {xor|and|or} convolution.
      E.g.  if vec = xor_conv(vec1, vec2) then
               vec[k] = \sum {vec1[i] * vec2[j] | i ^ j = k}
      The sizes of vec? need not be powers of two.
  
    void xor_conv_dest(vector<T>& vec1, vector<T>& vec2);
    void and_conv_dest(vector<T>& vec1, vector<T>& vec2);
    void or_conv_dest(vector<T>& vec1, vector<T>& vec2);
      Performs {xor|and|or} convolution destructively.
      The result will be set in vec1.  Both vec1 and vec2 are destructed.
      The sizes of vec? need not be powers of two.
  
    void hadamard(vector<T>& vec);
    void inv_hadamard(vector<T>& vec);
    void zeta_upper(vector<T>& vec);
    void moebius_upper(vector<T>& vec);
    void zeta_lower(vector<T>& vec);
    void moebius_lower(vector<T>& vec);
      Performs corresponding transformation of vec.  
      The result will be set in vec.
      The size of vec MUST be a power of two.
  
    int trans_resize(vector<T>& x);
      Resizes x to a power of two.  Returns the new size.
    int trans_resize(vector<T>& x, vector<T>& y);
      Resizes x and y to (the same) power of two.  Returns the new size.

  Notice:

    Definitions of zeta/moebius transformations:

      For f : power(S) -> T,  zeta_upper(f) : power(S) -> T
        zeta_upper(f)(X) := \sum { f(Y) | X \subseteq Y }
        zeta_lower(f)(X) := \sum { f(Y) | Y \subseteq X }
        moebius_upper(f) := inverse of zeta_upper
        moebius_lower(f) := inverse of zeta_lower

      In the functions of this library, f is encoded with 
        vec[x] = f(X)  where ((x >> t) & 1) == 1 <=> t \in X

      The complexity is O(N 2^N) where vec.size() == 2^N.

    For hadamard transformations, 
      refer to https://yamate11.github.io/blog/posts/2021/08-10-xor-conv/

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- fastTransform.cc

template <typename T>
int trans_resize(vector<T>& x, vector<T>& y) {
  int n = max(x.size(), y.size());
  int p = 31 - __builtin_clz(n);
  int t = 1 << p;
  if (n > t) t *= 2;
  x.resize(t);
  y.resize(t);
  return t;
}

template<typename T>
int trans_resize(vector<T>& x) { return trans_resize(x, x); }

template<typename T, int p1, int p2, int p3, int p4, int div>
void _trans_form(vector<T>& f) {
  int n = f.size();
  for (int i = 1; i < n; i *= 2) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = f[j];
        T y = f[j | i];
        f[j    ] = (p1 * x + p2 * y) / div;
        f[j | i] = (p3 * x + p4 * y) / div;
      }
    }
  }
}

template <typename T>
void hadamard(vector<T>& f) { _trans_form<T, 1, 1, 1, -1, 1>(f); }

template <typename T>
void inv_hadamard(vector<T>& f) { _trans_form<T, 1, 1, 1, -1, 2>(f); }

template<typename T>
void zeta_upper(vector<T>& f) { _trans_form<T, 1, 1, 0, 1, 1>(f); }

template<typename T>
void moebius_upper(vector<T>& f) { _trans_form<T, 1, -1, 0, 1, 1>(f); }

template<typename T>
void zeta_lower(vector<T>& f) { _trans_form<T, 1, 0, 1, 1, 1>(f); }

template<typename T>
void moebius_lower(vector<T>& f) { _trans_form<T, 1, 0, -1, 1, 1>(f); }

template<typename T>
void _conv_dest_form(vector<T>& x, vector<T>& y,
                     void fwd(vector<T>&), void bwd(vector<T>&)) {
  int t = trans_resize(x, y);
  fwd(x);
  fwd(y);
  for (int i = 0; i < t; i++) x[i] *= y[i];
  bwd(x);
}

template<typename T>
void xor_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, hadamard, inv_hadamard);
}

template<typename T>
void and_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, zeta_upper, moebius_upper);
}

template<typename T>
void or_conv_dest(vector<T>& x, vector<T>& y) {
  _conv_dest_form(x, y, zeta_lower, moebius_lower);
}

template <typename T>
vector<T> xor_conv(vector<T> x, vector<T> y) {
  xor_conv_dest(x, y);
  return x;
}

template <typename T>
vector<T> and_conv(vector<T> x, vector<T> y) {
  and_conv_dest(x, y);
  return x;
}

template <typename T>
vector<T> or_conv(vector<T> x, vector<T> y) {
  or_conv_dest(x, y);
  return x;
}

// @@ !! END ---- fastTransform.cc
