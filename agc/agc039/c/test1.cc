#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// sieve(upto) returns the list of prime numbers up to upto.
//   Size: upto(1e8).size() ... 5.7e6,  upto(1e9).size() ... 5.1e7
//   Performance: upto(1e8) ... 0.7sec,   upto(1e9) ... 9.2sec
vector<int> sieve(int upto) {
  vector<int> res;
  vector<bool> tbl(upto+1);
  ll lim = (int)(sqrt((double)upto)) + 1;
  for (int x = 2; x <= upto; x++) {
    if (tbl.at(x))  continue;
    res.push_back(x);
    if (x > lim)  continue;
    for (int y = x * 2; y <= upto; y += x) tbl.at(y) = true;
  }
  return res;
}

/*
  Prime Factorization
    Two versions:
      - prfac(n)
      - prfac(n, primes)
 */

vector<pair<ll, int>> prfac(ll n, const vector<int>& primes) {
  //      primes should contain prime numbers at least up to sqrt(n)
  vector<pair<ll, int>> res;
  ll x = n;
  for (ll p : primes) {
    if (x == 1)  break;
    if (p * p > x)  break;
    if (x % p != 0)  continue;
    int c = 1;
    x /= p;
    while (x % p == 0) {
      c += 1;
      x /= p;
    }
    res.push_back(make_pair(p, c));
  }
  if (x != 1)  res.push_back(make_pair(x, 1));
  return res;
}

vector<pair<ll, int>> prfac(ll n) {
  return prfac(n, sieve((int)(sqrt((double)n)) + 1));
}

/*
    List of divisors
      - getDivisors(n)
    Note: the results are NOT sorted
 */

// gdsub ... aux function used in getDivisors()
vector<ll> gdsub(int i, int n, auto fs) {
  if (i == n) { return vector<ll>({1}); }
  auto part = gdsub(i+1, n, fs);
  ll p  = fs.at(i).first;
  int r = fs.at(i).second;
  ll pp = p;    // pp = p^m, for m \in [1, r]
  int partOrigLen = part.size();
  for (int m = 1; m <= r; m++) {
    for (int j = 0; j < partOrigLen; j++) {
      part.push_back(pp * part.at(j));
    }
    pp *= p;
  }
  return part;
}

vector<ll> getDivisors(ll n) {
  auto fs = prfac(n);
  return gdsub(0, fs.size(), fs);
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

// ----------------------------------------------------------------------

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto primes = sieve(100);  // List of prime numbers up to 100

  auto calc = [&](ll n) {
    auto sub = fix([&](auto recF, ll t, ll i) -> ll {
	ll p = primes.at(i);
	ll vmax = 1;
	for (ll q = p, r = 1; t * q <= n; q *= p, r++) {
	  ll x = recF(t * q, i+1);
	  vmax = max(vmax, (r+1) * x);
	}
	return vmax;
      });
    return sub(1, 0);
  };
    
  auto foo = [&](ll k) {
    cout << "10^" << k << " " << calc(pow(10, k)) << endl;
  };

  for (int i = 1; i <= 9; i++) foo(i);

  return 0;
}

