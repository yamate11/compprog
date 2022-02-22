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

template<typename T, typename = void>
struct has_func_zero_s { static constexpr bool value = false; };

template<typename T> 
struct has_func_zero_s<T, enable_if_t<is_member_function_pointer_v<decltype(&T::zero)>>> {
  static constexpr bool value = is_member_function_pointer_v<decltype(&T::zero)>; 
};

template<typename T> 
constexpr T zero(T t) { if constexpr (has_func_zero_s<T>::value) return t.zero();  else return (T)0; }

template<typename T, typename = void>
struct has_func_one_s { static constexpr bool value = false; };

template<typename T> 
struct has_func_one_s<T, enable_if_t<is_member_function_pointer_v<decltype(&T::one)>>> {
  static constexpr bool value = is_member_function_pointer_v<decltype(&T::one)>; 
};

template<typename T> 
constexpr T one(T t) { if constexpr (has_func_one_s<T>::value) return t.one();  else return (T)1; }

// ---

struct X {
  int v;
  X zero() const { return X(20); }
  X(int v_) : v(v_) {}
  operator int() const { return v; }
};

struct Y {
  operator int() const { return 30; }
  Y(int v_) {}
};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  X x(40);
  Y y(50);
  cout << (int)zero<X>(x) << endl;
  cout << (int)zero<Y>(y) << endl;
  cout << zero<int>(10) << endl;
  cout << zero<double>(3.5) << endl;

  return 0;
}

