#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<vector<int>> nbr(N);
  unordered_map<int, unordered_map<int, int>> mp;
  for (int i = 0; i < N-1; i++) {
    int a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
    mp[a][b] = i;
  }
  int K = 0;
  for (int i = 0; i < N; i++) K = max(K, (int)nbr.at(i).size());
  
  vector<int> colors(N-1);

  auto func = fix([&](auto recF, int n, int p, int c) -> void {
      int nc = 0;
      for (int x : nbr.at(n)) {
	if (x == p) continue;
	if (nc == c) nc++;
	int m1 = min(x, n);
	int m2 = max(x, n);
	colors.at(mp.at(m1).at(m2)) = nc;
	recF(x, n, nc);
	nc++;
      }
    });
  
  func(0, -1, -1);

  cout << K << "\n";
  for (int i = 0; i < N-1; i++) cout << 1 + colors.at(i) << "\n";

  return 0;
}

