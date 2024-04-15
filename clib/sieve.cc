#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  sieve.cc -- prime numbers and factorization

  vector<int> primes = sieve(n);
    // Returns the list of prime numbers upto n.
    // Performance:
    //   Size: upto(1e8).size() ... 5.7e6,  upto(1e9).size() ... 5.1e7
    //   Speed: upto(1e8) ... 0.7sec,   upto(1e9) ... 9.2sec

  vector<int> divSieve = divisorSieve(n);
    // Returns the list of the least prime divisors upto n.
    // E.g. divSieve[2] == 2, divSieve[15] == 3, divSieve[77] == 7, etc.

  vector<pair<ll, int>>  pr = prfac(m);
  vector<pair<ll, int>>  pr = prfac(m, primes);
  vector<pair<int, int>> pr = prfacDivSieve(m, divSieve);
    // Returns the prime factorization results.
    // The latter is naturally faster.
    // primes should contain prime numbers at least up to sqrt(m)
    // divSieve should contain divisors upto m.
    // Performance of `` REP(i, 1, N) prfac(i, primes) ''
    //   i = 1<<17 (1.3e5) ... 40 ms,  i = 1<<20 (1.0e6) ... 510 ms,   i = 1<<22 (4.2e6) ... 2900 ms
    // Performance of `` REP(i, 1, N) prfacDivSieve(i, divSieve) ''
    //   i = 1<<17 (1.3e5) ... 13 ms,  i = 1<<20 (1.0e6) ... 110 ms,   i = 1<<22 (4.2e6) ... 450 ms

  vector<ll>  divs = getDivisors(m);
  vector<ll>  divs = getDivisors(m, primes);
  vector<ll>  divs = getDivisorsDivSieve(m, divSieve);
    // Returns a list of all divisors of m.
    // NOTE: the results are *** NOT SORTED ***.
    // primes should contain prime numbers at least up to sqrt(m)
    // divSieve should contain divisors upto m.

*/

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- sieve.cc

// sieve(upto) returns the list of prime numbers up to upto.
//   Size: upto(1e8).size() ... 5.7e6,  upto(1e9).size() ... 5.1e7
//   Performance: upto(1e8) ... 0.7sec,   upto(1e9) ... 9.2sec
vector<int> sieve(int upto) {
  vector<int> res;
  vector<bool> tbl(upto+1);
  ll lim = (int)(sqrt((double)upto)) + 1;
  for (int x = 2; x <= upto; x++) {
    if (tbl[x]) continue;
    res.push_back(x);
    if (x <= lim) {
      for (int y = x * x; y <= upto; y += x) tbl[y] = true;
    }
  }
  return res;
}

vector<int> divisorSieve(int upto) {
  vector<int> tbl(upto+1);
  iota(tbl.begin(), tbl.end(), 0);
  ll lim = (int)(sqrt((double)upto)) + 1;
  for (int x = 2; x <= lim; x++) {
    if (tbl[x] < x) continue;
    for (int y = x * x; y <= upto; y += x) if (tbl[y] == y) tbl[y] = x;
  }
  return tbl;
}

/*
  Prime Factorization
    Two versions:
      - prfac(n)
      - prfac(n, primes)
            primes should contain prime numbers at least up to sqrt(n)
 */

struct myiter_primes {
  const vector<int>& primes;
  int i;
  myiter_primes(const auto& primes_) : primes(primes_), i(0) {}
  int next() {
    if (i == ssize(primes)) return -1;
    else return primes[i++];
  }
};

struct myiter_int {
  int x;
  myiter_int() : x(0) {}
  int next() {
    x++;
    if (x == 1) { return 2; }
    if (x == 2) { return 3; }
    if (x % 2 == 1) { return 3 * x - 4; }
    return 3 * x - 5;
  }
};

vector<pair<ll, int>> _prfac_sub(ll n, auto& mit) {
  vector<pair<ll, int>> res;
  ll x = n;
  while (x > 1) {
    ll p = mit.next();
    if (p < 0) {
      throw runtime_error("_prfac_sub: prime range too small");
    }
    if (p * p > x) break;
    int r = 0;
    while (x % p == 0) {
      x /= p;
      r++;
    }
    if (r > 0) res.push_back(make_pair(p, r));
  }
  if (x > 1) res.push_back(make_pair(x, 1));
  return res;
}

vector<pair<ll, int>> prfac(ll n) {
  myiter_int mit;
  return _prfac_sub(n, mit);
}
vector<pair<ll, int>> prfac(ll n, const vector<int>& primes) {
  myiter_primes mit(primes);
  return _prfac_sub(n, mit);
}

vector<pair<int, int>> prfacDivSieve(int n, const vector<int>& divSieve) {
  vector<pair<int, int>> ret;
  int p = -1;
  int r = 0;
  while (n > 1) {
    int q = divSieve[n];
    if (p == q) {
      r++;
    }else {
      if (p > 0) ret.emplace_back(p, r);
      p = q;
      r = 1;
    }
    n /= p;
  }
  if (p > 0) ret.emplace_back(p, r);
  return ret;
}

/*
    List of divisors
      - getDivisors(n)
      - getDivisors(n, primes)
            primes should contain prime numbers at least up to sqrt(n)
    Note: the results are NOT sorted
 */

// _gdsub ... aux function used in getDivisors()
vector<ll> _gdsub(int i, const auto& fs) {
  if (i == (int)fs.size()) { return vector<ll>({1}); }
  auto part = _gdsub(i+1, fs);
  auto [p, r] = fs[i];
  ll pp = p;    // pp = p^m, for m \in [1, r]
  int partOrigLen = part.size();
  for (int m = 1; m <= r; m++) {
    for (int j = 0; j < partOrigLen; j++) part.push_back(pp * part[j]);
    pp *= p;
  }
  return part;
}

vector<ll> getDivisors(ll n) { return _gdsub(0, prfac(n)); }
vector<ll> getDivisors(ll n, const vector<int>& primes) { return _gdsub(0, prfac(n, primes)); }
vector<ll> getDivisorsDivSieve(ll n, const vector<int>& divSieve) { return _gdsub(0, prfacDivSieve(n, divSieve)); }

// @@ !! END ---- sieve.cc
