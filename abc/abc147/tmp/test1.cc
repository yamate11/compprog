#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int gx = 3;

ll func3(ll y) {
  if (y == 0) return gx;
  return y + func3(y-1);
}

// --- FIX begin --- cut here ---
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
// --- FIX end --- cut here ---

int main() {
  int x = 3;

  /*
  auto func1 = [&](int y) -> int {
    return x + y;
  };
  */

  auto func2 = [&](const auto& recF, ll y) -> ll {
    if (y == 0) return x;
    return y + recF(recF, y-1);
  };

  auto func4 = fix([&](const auto& recF, ll y) -> ll {
      if (y == 0) return x;
      return y + recF(y-1);
    });

  cout << func2(func2, 1e9) << endl;
  // cout << func3(1e10) << endl;
  // cout << func4(1e9) << endl;

}
