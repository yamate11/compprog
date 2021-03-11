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

  ll N, X, D; cin >> N >> X >> D;

  vector<ll> vals;
  for (int i = 0; i < N; i++) {
    vals.push_back(X);
    X += D;
  }
  
  set<ll> vset;
  auto fcnt = fix([&](auto recF, ll j, ll s, ll t) -> void {
      if (j == (ll)vals.size()) {
	vset.insert(s - t);
	return;
      }
      recF(j+1, s + vals.at(j), t);
      recF(j+1, s, t + vals.at(j));
    });
  fcnt(0, 0, 0);
  cout << vset.size() << endl;


  return 0;
}

