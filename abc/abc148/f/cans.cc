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

  int N; cin >> N;
  int u, v; cin >> u >> v; u--; v--;
  vector<vector<int>> nbr(N);
  for (int i = 0; i < N-1; i++) {
    int a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  
  vector<int> path;
  auto phase1 = fix([&](const auto& recF, int n, int p, int dist) -> bool {
      if (n == u) {
	path.resize(dist+1);
	path.at(dist) = u;
	return true;
      }
      for (int k : nbr.at(n)) {
	if (k == p) continue;
	if (recF(k, n, dist + 1)) {
	  path.at(dist) = n;
	  return true;
	}
      }
      return false;
    });
  bool b = phase1(v, -1, 0);
  assert(b);
  assert(path.size() >= 2);
  int thr = (path.size() - 1) / 2;
  int pp = path.at(thr);
  int tt = path.at(thr+1);
  
  auto phase2 = fix([&](const auto& recF, int n, int p) -> int {
      int dmax = 0;
      for (int k : nbr.at(n)) {
	if (k == p) continue;
	dmax = max(dmax, recF(k, n) + 1);
      }
      return dmax;
    });
  int len2 = phase2(tt, pp);
  int answer = thr + 1 + len2 - 1;
  cout << answer << endl;
  

  return 0;
}

