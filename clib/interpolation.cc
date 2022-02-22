#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  interpolation.cc 

  TYPICAL USAGE

      using Pol = PolyFpA;
      using Fp = FpA;
      vector<Fp> vs = {0, 1, 4};
      Pol p = lagrangePol<Pol>(vs);  // p == X*X
      Fp y = lagrangeVal(vs, 10);    // y == 10*10 == 100
      vector<Fp> ws = {1, 1, 2, 3, 5, 8, 13, 21, 34};
      auto optPQ = fitFPS<Pol>(ws, 3);
      assert(optPQ);
      auto [p1, q1] = *optPQ;       // p1 == 1,  q1 == 1 - X - X^2


  The type of coefficients must be a field.
  The following functions are defined.

  template<typename Pol>
  Pol lagrangePol(const vector<T>& vs)
    Lagrange Interpolation
    This function returns the interpolated polynomial of degree deg.
    The template parameter usually cannot be omitted.
    vs is a vector of values at point 0, 1, 2, ..., deg

  template<typename T>
  T lagrangeVal(const vector<T>& vs, ll n) {
    Lagrange Interpolation
    This function returns the value of the interpolated polynomial
    of degree deg, at x = n.
    vs is a vector of values at point 0, 1, 2, ..., deg
  
  template<typename Pol>
  optional<pair<Pol, Pol>> fitFPS(const vector<T>& vs, int verify) {
    Finds a pair of polynomial (p, q) such that the first several
    terms of the formal power series p / q coincide with vs.
    verify is the number of terms to test whether both terms are equal.
    It is recommended to have vs.size() >= 2 * deg + verify where deg
    is an estimated upper limit of degree of q.
    Usually, the template parameter Pol cannot be omittted.
*/


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(polynomial matrix) ---- convolution.cc

#if ! defined(DLOG_LIB)
  #define DLOG_LIB(...)
  #define DLOGK_LIB(...)
  #define DLOGKL_LIB(lab, ...)
#endif

template<typename Pol>
Pol lagrangePol(const vector<typename Pol::value_type>& vs) {
  using T = typename Pol::value_type;
  using SP = typename Pol::SP;
  int k = vs.size() - 1;
  vector<T> fact(k + 1);
  fact[0] = one<T>(vs[0]);
  for (ll i = 0; i < k; i++) fact[i + 1] = fact[i] * (T)(i + 1);
  Pol aux(one<T>(vs[0]));
  for (int i = 0; i <= k; i++) aux *= SP::X - (T)i;
  Pol ret;
  for (int i = 0; i <= k; i++) {
    T c = vs[i] / (fact[i] * fact[k - i]);
    if ((k - i) % 2 != 0) c = -c;
    auto [d, m] = aux.divideLinear(i);
    assert(m == (T)0);
    ret += d * c;
  }
  return ret;
}

template<typename T>
T lagrangeVal(const vector<T>& vs, ll n) {
  int k = vs.size() - 1;
  vector<T> fact(k + 1);
  vector<T> invfact(k + 1);
  fact[0] = one<T>(vs[0]);
  for (ll i = 0; i < k; i++) fact[i + 1] = fact[i] * (T)(i + 1);
  invfact[k] = one<T>(vs[0]) / fact[k];
  for (ll i = k; i >= 1; i--) invfact[i - 1] = i * invfact[i];
  vector<T> qF(k + 1), qB(k + 1);
  // T q = (T)1;
  qF[0] = qB[k] = one<T>(vs[0]);
  for (int i = 0; i < k; i++) {
    T tt = T(n - i);
    if (tt == (T)0) return vs[i];
    qF[i + 1] = qF[i] * tt;
  }
  for (int i = k; i > 0; i--) {
    qB[i - 1] = qB[i] * T(n - i);
  }
  T ret = (T)0;
  for (int i = 0; i <= k; i++) {
    T c = vs[i] * invfact[i] * invfact[k - i];
    if ((k - i) % 2 != 0) c = -c;
    T d = qF[i] * qB[i];
    ret += d * c;
  }
  return ret;
}

template<typename Pol>
optional<pair<Pol, Pol>>
fitFPS(const vector<typename Pol::value_type>& vec, int verify) {
  using T = typename Pol::value_type;

  auto checkSol = [&](const Matrix<T>& sol) -> bool {
    int d = sol.dimI;
    // DLOGKL("checkSol", d);
    for (int i = 0; i < verify; i++) {
      T y = (T)0;
      for (int j = 0; j < d; j++) { y += sol.at(j, 0) * vec[2*d - 1 + i - j]; }
      // DLOGK(i, y - vec[2*d + i]);
      if (vec[2*d + i] != y) {
        // DLOG("false");
        return false;
      }
    }
    return true;
  };

  auto findQ = [&]() -> optional<Pol> {
    int sz = vec.size();
    for (int d = 1; 2 * d + verify < sz; d++) {
      Matrix<T> mat(d, d);
      vector<T> bs(d);
      for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) { mat.at(i, j) = vec[d - 1 + i - j]; }
        bs[i] = vec[d + i];
      }
      // DLOGK(d, bs, mat);
      Matrix<T> mm(0, 1, bs);
      auto optsol = mat.template linSolution<false>(mm);
      if (!optsol) continue;
      auto& [sol, _] = *optsol;
      // DLOGK(d, sol);
      if (checkSol(sol)) {
        vector<T> q(sol.dimI + 1);
        q[0] = one<T>(vec[0]);
        for (int i = 0; i < (int)sol.dimI; i++) { q[i + 1] = -sol.at(i, 0); }
        return make_optional(Pol(q));
      }
    }
    return nullopt;
  };

  auto optq = findQ();
  if (!optq) return nullopt;
  Pol q = move(*optq);
  Pol p = Pol(vec).cutoff(q.degree()) * q;
  p.selfCutoff(q.degree() - 1);
  return make_optional(make_pair(move(p), move(q)));
}

// @@ !! END ---- interpolation.cc
