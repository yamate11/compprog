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
  int root = -1;
  vector<int> parent(N);
  vector<vector<int>> children(N);
  for (int i = 0; i < N; i++) {
    int p; cin >> p; p--;
    if (p < 0) {
      root = i;
      parent.at(root) = root;
    }
    else {
      parent.at(i) = p;
      children.at(p).push_back(i);
    }
  }
  vector<int> level(N);
  auto dfs1 = fix([&](const auto& recF, int n, int lv) -> void{
      level.at(n) = lv;
      for (int c : children.at(n)) {
	recF(c, lv+1);
      }
    });
  dfs1(root, 0);
  
  vector<vector<int>> cum;
  cum.push_back(move(parent));
  for (int i = 1; true; i++) {
    bool done = true;
    vector<int> v(N);
    for (int j = 0; j < N; j++) {
      v.at(j) = cum.at(i-1).at(cum.at(i-1).at(j));
      if (v.at(j) != root) done = false;
    }
    cum.push_back(move(v));
    if (done) break;
  }
  
  auto reports = [&](int i, int j) -> bool {
    if (level.at(i) <= level.at(j)) return false;
    int d = level.at(i) - level.at(j);
    int idx = 0;
    int p = i;
    while (d > 0) {
      if (d % 2 == 1) p = cum.at(idx).at(p);
      d /= 2;
      idx++;
    }
    return p == j;
  };

  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b; a--; b--;
    cout << (reports(a, b) ? "Yes" : "No") << "\n";
  }

  return 0;
}

