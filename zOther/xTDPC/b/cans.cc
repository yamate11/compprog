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

struct GI {
  int ch;
  int g1;
  int g2;
  GI(int _ch, int _g1, int _g2) : ch(_ch), g1(_g1), g2(_g2) {}
};

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int A, B; cin >> A >> B;
  vector<int> a(A), b(B);
  for (int i = 0; i < A; i++) cin >> a.at(i);
  for (int i = 0; i < B; i++) cin >> b.at(i);
  
  GI dummy(-1,0,0);
  vector<vector<GI>> memo(A+1, vector<GI>(B+1, dummy));
  memo.at(1).at(0) = GI(0, a.at(A-1), 0);
  memo.at(0).at(1) = GI(1, b.at(B-1), 0);
  auto func = fix([&](auto recF, int ra, int rb) -> GI {
      GI& ref = memo.at(ra).at(rb);
      if (ref.ch != -1) return ref;
      if (ra == 0) {
	const GI& gi = recF(0, rb-1);
	ref = GI(1, b.at(B - rb) + gi.g2, gi.g1);
      }else if (rb == 0) {
	const GI& gi = recF(ra-1, 0);
	ref = GI(0, a.at(A - ra) + gi.g2, gi.g1);
      }else {
	const GI& giA = recF(ra-1, rb);
	int ptA = a.at(A - ra) + giA.g2;
	const GI& giB = recF(ra, rb-1);
	int ptB = b.at(B - rb) + giB.g2;
	ref = ptA > ptB ? GI(0, ptA, giA.g1) : GI(1, ptB, giB.g1);
      }
      return ref;
    });

  GI gi = func(A, B);
  cout << gi.g1 << endl;

  return 0;
}

