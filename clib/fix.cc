#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Recursive Function with Closure
    Original: http://koturn.hatenablog.com/entry/2018/06/10/060000

  Usage:
    auto func = fix([&](const auto& f, type1 var1, ...) -> typeRet {
                  // function body, where recursive call should be done via
		  // f(exp1, ...) instead of func(exp1, ...)
    });
    func(exp1, ...);

    Note that "-> typeRet" cannot be omitted.

  Note: 
    If recursive call is not needed, write simply as follows:
      auto func = [&](type1 var1, ...) { ... };
    The point is that you should not use std::function<...> for performance.
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- fix.cc
template<typename F>
class FixPoint : private F {
public:
  explicit constexpr FixPoint(F&& f) noexcept : F(forward<F>(f)) {}

  template<typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template<typename F>
static inline constexpr decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}
// @@ !! END ---- fix.cc

int main() {

  int fib10 = fix([](auto f, int n) -> int {
      return n < 2 ? n : (f(n - 1) + f(n - 2));
    })(10);
  assert(fib10 == 55);

  int t0 = 5;
  auto func1 = fix([&](auto f, int n) -> int {
      if (n == 0) return t0;
      else        return n + f(n-1);
    });
  assert(func1(4) == 15);

  vector<vector<int>> nbr({
      vector<int>({1,2}),
	vector<int>({0}),
	vector<int>({0,3,4}),
	vector<int>({2,5}),
	vector<int>({2}),
	vector<int>({3})
    });
  /*
        0 -+- 1
           +- 2 -+- 3 --- 5
                 +- 4
   */
  vector<int> in, out;
  auto dfs = fix([&](auto f, int node, int parent) -> void {
      in.push_back(node);
      for (int c : nbr.at(node)) {
	if (c == parent) continue;
	f(c, node);
      }
      out.push_back(node);
    });
  dfs(0, -1);
  assert(in == vector<int>({0, 1, 2, 3, 5, 4}));
  assert(out == vector<int>({1, 5, 3, 4, 2, 0}));

  cout << "ok\n";
}
