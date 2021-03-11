#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if defined(DEBUG)

#include <unistd.h>
#include <sys/fcntl.h>
#define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
#define DCALL(func, ...) func(__VA_ARGS__)

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#else  // defined(DEBUG)

#define DLOG(...)
#define DCALL(func, ...)

#endif // defined(DEBUG)

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

// prime factorization
vector<pair<ll, ll>> prfac(ll n) {
  return prfac(n, sieve((ll)(sqrt((double)n)) + 1));
}

// list of divisors
//     note: not sorted
vector<ll> gdsub(ll i, ll n, auto fs) {
  if (i == n) { return vector<ll>({1}); }
  auto part = gdsub(i+1, n, fs);
  ll len = part.size();
  auto t = fs.at(i);
  ll p = t.first;
  ll r = t.second;
  ll pp = p;
  for (ll m = 1; m <= r; m++) {
    for (ll j = 0; j < len; j++) {
      part.push_back(pp * part.at(j));
    }
    pp *= p;
  }
  return part;
}

vector<ll> getDivisors(ll n) {
  ll s = sqrt(n);
  auto primes = sieve(s+1);
  vector<pair<ll, ll>> fs = prfac(n, primes);
  return gdsub(0, fs.size(), fs);
}


bool chk(ll b, ll n, ll s) {
  ll t = 0;
  while (n > 0) {
    t += n % b;
    n /= b;
  }
  return t == s;
}

ll solve(ll n, ll s) {
  if (n < s) return -1;
  if (n == s) return n+1;
  ll sqrtN = sqrt(n);
  for (ll b = 2; b <= sqrtN; b++) {
    if (chk(b, n, s)) return b;
  }
  vector<ll> vDiv = getDivisors(n-s);
  sort(vDiv.begin(), vDiv.end());
  int k = vDiv.size();
  for (int j = k/2; j < k; j++) {
    ll b = vDiv[j] + 1;
    ll x = (n - s) / (b - 1);
    if (x < b && 0 <= s - x && s - x < b) return b;
  }
  return -1;
}

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cout << setprecision(20);

  ll n, s; cin >> n >> s;
  cout << solve(n, s) << endl;
  return 0;
}

