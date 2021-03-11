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
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<vector<int>> win(N);
  for (int i = 0; i < N-1; i++) {
    int a; cin >> a; a--;
    win.at(a).push_back(i+1);
  }

  auto depth = fix([&](auto recF, int n) -> int {
      vector<int> ds;
      for (int i : win.at(n)) ds.push_back(recF(i));
      sort(ds.begin(), ds.end(), greater<int>());
      int ret = 0;
      for (int i = 0; i < (int)ds.size(); i++) {
	ret = max(ret, i + 1 + ds.at(i));
      }
      return ret;
    });
  
  cout << depth(0) << endl;
  return 0;
}

