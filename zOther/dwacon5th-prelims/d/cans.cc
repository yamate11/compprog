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

  int N, D; cin >> N >> D;
  vector<vector<int>> num(D, vector<int>(D));
  vector<vector<int>> rank(D, vector<int>(D));
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    num.at(x % D).at(y % D)++;
  }
  int vmax = 0;
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < D; j++) vmax = max(vmax, num.at(i).at(j));
  }
  int k = ceil(sqrt(vmax) - 0.001);
  
  
  for (int x = 0; x < D; x++) {
    for (int y = 0; y < D; y++) {
      rank.at(x).at(y) =
	num.at(x).at(y) <= (k-1)*(k-1) ? 0 :
	num.at(x).at(y) <=   k  *(k-1) ? 1 : 2;
    }
  }

  auto setCum = [&](int th) {
    vector<vector<int>> cum(2*D + 1, vector<int>(2*D + 1));
    for (int x = 0; x < 2*D; x++) {
      for (int y = 0; y < 2*D; y++) {
	cum.at(x+1).at(y+1) = (rank.at(x % D).at(y % D) >= th ? 1 : 0)
	  + cum.at(x).at(y+1) + cum.at(x+1).at(y)
	  - cum.at(x).at(y);
      }
    }
    return cum;
  };
  auto cum1 = setCum(1);
  auto cum2 = setCum(2);

  auto emp = [&](int th, int x, int y, int dx, int dy) {
    const auto& cum = th == 1 ? cum1 : cum2;
    int n = cum.at(x + dx).at(y + dy) + cum.at(x).at(y)
            - cum.at(x + dx).at(y) - cum.at(x).at(y + dy);
    return n == 0;
  };

  auto chk = [&](int m) {
    for (int x = 0; x < D; x++) {
      for (int y = 0; y < D; y++) {
	if (emp(1, x + m, y + m, D - m, D - m) &&
	    emp(2, x + m, y,     D - m, m) &&
	    emp(2, x,     y + m, D,     D - m)) {
	  return true;
	}
      }
    }
    return false;
  };

  int lo = 0, hi = D;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (chk(mid)) hi = mid;
    else lo = mid;
  }
  cout << (k - 1) * D + lo << endl;

}
