#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Progression
  (currently, only for Kitamasa Method)

  * Kitamasa Method

    See https://yamate11.hatenablog.com/entry/2021/04/30/170904

    * Recurrence Formula
      a_{n+k} = d_0 a_{n + 0} + ... + d_{k-1} a_{n + k-1}
      (or, equivalently,
         a_n = d_{k-1} a_{n-1} + ... + d_0 a_{n - k})
  
    * T kitamasa(const vector<T>& vec_d, const vector<T>& vec_a0, int n)
       - returns a_{n}
       - vec_d : [d_0, ..., d_{k-1}]
       - vec_a0 : [a_0, ..., a_{k-1}]
       - Be aware that vector starts 0.  Given info may be in the reverse order

    * vector<T> ktms_coef(const vector<T>& vec_d, int n)
       - returns coefficient vector vec_x of length k
         that can be used in ktms_rep

    * T ktms_rep(const vector<T>& vec_x, const vector<T>& a0)
       - returns a_{n}
       - kitamasa(vec_d, vec_a0, n) = ktms_rep(ktms_coef(vec_d, n), vec_a0)

*/

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- progression.cc

template<typename T>
vector<T> ktms_coef(const vector<T>& vec_d, int n) {
  int sz = vec_d.size();

  auto incr_x = [&](const vector<T>& vec_x) -> vector<T> {
    auto ret = vector<T>(sz);
    for (int i = 0; i + 1 < sz; i++) ret[i + 1] = vec_x[i];
    for (int i = 0; i < sz; i++) ret[i] += vec_x[sz - 1] * vec_d[i];
    return ret;
  };

  auto dbl_x = [&](const vector<T>& vec_x) -> vector<T> {
    auto tmp = vector(sz, vector<T>(sz));
    tmp[0] = vec_x;
    for (int i = 0; i + 1 < sz; i++) { tmp[i + 1] = incr_x(tmp[i]); }
    auto ret = vector<T>(sz);
    for (int i = 0; i < sz; i++) {
      T s = (T)0;
      for (int j = 0; j < sz; j++) { s += vec_x[j] * tmp[j][i]; }
      ret[i] = s;
    }
    return ret;
  };

  auto op = vector<int>();
  while (n > 0) {
    if (n % 2 == 1) {
      op.push_back(1);
      n--;
    }else {
      op.push_back(2);
      n /= 2;
    }
  }
  auto vec_x = vector<T>(sz);
  vec_x[0] = (T)1;
  for (int i = (int)op.size() - 1; i >= 0; i--) {
    if (op[i] == 1) vec_x = incr_x(vec_x);
    else            vec_x = dbl_x(vec_x);
  }
  return vec_x;
}

template<typename T>
T ktms_rep(const vector<T>& vec_x, const vector<T>& vec_a0) {
  assert(vec_x.size() == vec_a0.size());
  T ret = (T)0;
  for (int i = 0; i < (int)vec_x.size(); i++) {
    ret += vec_x[i] * vec_a0[i];
  }
  return ret;
}

template<typename T>
T kitamasa(const vector<T>& vec_d, const vector<T>& vec_a0, int n) {
  return ktms_rep(ktms_coef(vec_d, n), vec_a0);
}


// @@ !! END ---- progression.cc

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    auto vec_d = vector<ll>({1, 1});
    auto vec_a0 = vector<ll>({0, 1});
    assert(kitamasa(vec_d, vec_a0, 2) == 1);
    assert(kitamasa(vec_d, vec_a0, 3) == 2);
    assert(kitamasa(vec_d, vec_a0, 4) == 3);
    assert(kitamasa(vec_d, vec_a0, 5) == 5);
    assert(kitamasa(vec_d, vec_a0, 6) == 8);
    assert(kitamasa(vec_d, vec_a0, 7) == 13);
    assert(kitamasa(vec_d, vec_a0, 8) == 21);
  }

  auto compare_naive = [&](const vector<ll>& vec_d,
                           vector<ll> vec_a0, int m) -> void {
    int k = vec_d.size();
    assert((int)vec_a0.size() == k);
    for (int i = 0; i < k; i++) {
      assert(kitamasa(vec_d, vec_a0, i) == vec_a0[i]);
    }
    vector<ll> va(vec_a0);
    for (int i = k; i <= m; i++) {
      ll y = 0;
      for (int j = 0; j < k; j++) y += vec_d[j] * va[j];
      assert(kitamasa(vec_d, vec_a0, i) == y);
      for (int j = 0; j+1 < k; j++) va[j] = va[j + 1];
      va[k-1] = y;
    }
  };

  {
    auto vec1 = vector<ll>({1, 2, 3, 4});
    auto vec2 = vector<ll>({-2, -1, 0, 1});
    compare_naive(vec1, vec2, 20);
    compare_naive(vec2, vec1, 20);
  }

  cout << "ok" << endl;
  return 0;
  
}
