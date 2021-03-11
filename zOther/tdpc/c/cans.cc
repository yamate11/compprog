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

struct Info {
  int id;
  int rating;
  double prob;
  Info(int i, int r, double p) : id(i), rating(r), prob(p) {}
};

typedef vector<Info> Brd;

double winp(int x, int y) {
  return 1.0 / (1.0 + pow(10.0, (double)(y - x) / 400.0));
}

Brd compBrd(Brd b, Brd c) {
  Brd ret;
  for (Info w : b) {
    double x = 0;
    for (Info v : c) x += v.prob * winp(w.rating, v.rating);
    ret.emplace_back(w.id, w.rating, x * w.prob);
  }
  for (Info w : c) {
    double x = 0;
    for (Info v : b) x += v.prob * winp(w.rating, v.rating);
    ret.emplace_back(w.id, w.rating, x * w.prob);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int K; cin >> K;
  int N = 1 << K;
  vector<int> R(N);
  for (int i = 0; i < N; i++) cin >> R.at(i);
  auto func = fix([&](auto recF, int i, int n) -> Brd {
      if (n == 1) { return { Info(i, R.at(i), 1.0) }; }
      return compBrd(recF(i, n/2), recF(i + n/2, n/2));
    });

  Brd b = func(0, N);
  for (Info w : b) cout << w.prob << "\n";

  return 0;
}

