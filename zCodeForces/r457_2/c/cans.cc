#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(sieve)
// --> sieve
// ---- inserted library file sieve.cc

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

const vector<int> dummy_primes;

vector<pair<ll, int>> prfac(ll n, const vector<int>& primes = dummy_primes) {
  vector<int> tmp_primes;
  if (primes.size() == 0) {
    tmp_primes = sieve((int)sqrt((double)n) + 1);
  }
  const vector<int>& prms = primes.size() == 0 ? tmp_primes : primes;

  vector<pair<ll, int>> res;
  ll x = n;
  for (ll p : prms) {
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
vector<pair<ll, int>> prfac(ll n) {
  return prfac(n, sieve((int)(sqrt((double)n)) + 1));
}
*/

/*
    List of divisors
      - getDivisors(n)
      - getDivisors(n, primes)
            primes should contain prime numbers at least up to sqrt(n)
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

vector<ll> getDivisors(ll n, const vector<int>& primes = dummy_primes) {
  auto fs = prfac(n, primes);
  return gdsub(0, fs.size(), fs);
}

vector<ll> getDivisorsDivSieve(ll n, const vector<int>& divSieve) {
  auto fs = prfacDivSieve(n, divSieve);
  return gdsub(0, fs.size(), fs);
}


// ---- end sieve.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  if (n == 2) {
    cout << "2 2\n1 2 2\n";
    return 0;
  }
  /*
  if (n == 3 && m == 3) {
    cout << "2 3\n1 3 2\n1 2 1\n2 3 10000\n";
    return 0;
  }
  */
  auto primes = sieve(1e6);
  ll p = *lower_bound(primes.begin(), primes.end(), n);
  cout << "2 " << p << endl;
  cout << "1 " << n << " 2\n";
  cout << "1 2 " << p - n + 1 << "\n";
  for (ll i = 2; i <= n - 2; i++) cout << i << " " << i + 1 << " 1\n";
  ll cnt = n - 1;
  for (ll i = 1; i < n; i++) {
    for (ll j = i + 1; j <= n; j++) {
      if (cnt == m) break;
      if (i == 1 && j == n) continue;
      if (j < n && j == i + 1) continue;
      cout << i << " " << j << " " << ll(1e9) << "\n"; 
      cnt++;
    }
  }
  

  return 0;
}

