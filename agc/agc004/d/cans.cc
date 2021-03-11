#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, K; cin >> N >> K;
  vector<int> A(N);
  vector<vector<int>> src(N);
  for (int i = 0; i < N; i++) {
    int a; cin >> a; a--;
    A.at(i) = a;
    if (i > 0) src.at(a).push_back(i);
  }
  int cnt = 0;
  auto dfs = fix([&](const auto& recF, int x) -> int {
      int dd = 0;
      for (int y : src.at(x)) dd = max(dd, recF(y));
      if (x == 0 || dd + 1 == K) {
	if (A.at(x) != 0) cnt++;
	return 0;
      }
      return dd + 1;
    });
  dfs(0);
  cout << cnt << endl;

  return 0;
}

