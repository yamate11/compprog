#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

#include <type_traits>
#include <string>

template<typename T>
struct function_traits : function_traits<decltype(&T::operator())> {};

template<typename R, typename... Args>
struct function_traits<R(*)(Args...)> {
    using arg_type = std::tuple<Args...>;
};

template<typename C, typename R, typename... Args>
struct function_traits<R(C::*)(Args...) const> {
    using arg_type = std::tuple<Args...>;
};

template<typename T>
using first_argument_type = typename std::tuple_element<0, typename function_traits<T>::arg_type>::type;

int main() {
  auto f = [](std::string x) -> int { return x.size(); };

  // f の第一引数の型を取得
  using ArgType = first_argument_type<decltype(f)>;

  // ArgType は std::string になる
  ArgType a = "Hello";


  return 0;
}
