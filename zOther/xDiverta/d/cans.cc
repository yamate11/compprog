#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
  #define DFUNC(fname, ...) fname(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFUNC(fname, ...)
#endif

// sieve(upto) returns the list of prime numbers up to upto.
vector<ll> sieve(ll upto) {
  vector<ll> res;
  vector<bool> tbl(upto+1);
  ll lim = (ll)(sqrt((double)upto)) + 1;
  for (ll x = 2; x <= upto; x++) {
    if (tbl.at(x))  continue;
    res.push_back(x);
    if (x > lim)  continue;
    for (ll y = x * 2; y <= upto; y += x) tbl.at(y) = true;
  }
  return res;
}


// prime factorization
//      primes should contain prime numbers at least up to sqrt(n)
vector<pair<ll, ll>> prfac(ll n, const vector<ll>& primes) {
  vector<pair<ll, ll>> res;
  ll x = n;
  for (ll p : primes) {
    if (x == 1)  break;
    if (p * p > x)  break;
    if (x % p != 0)  continue;
    ll c = 1;
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

ll N;

ll sum = 0;

void calc(auto prf, ll idx, ll acc) {
  if (idx == (ll) prf.size()) {
    ll opp = N / acc;
    if (opp >= acc + 2)  sum += (opp-1);
    return;
  }
  if (acc * acc > N)  return;
  ll p = prf.at(idx).first;
  ll r = prf.at(idx).second;
  ll pr = 1;
  for (ll x = 0; x <= r; x++) {
    calc(prf, idx+1, acc*pr);
    pr *= p;
  }
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  ll lim = (ll)(sqrt(N)) + 2;
  auto primes = sieve(lim);
  auto prf = prfac(N, primes);
  
  sum = 0;
  calc(prf, 0, 1);
  cout << sum << endl;

  return 0;
}

