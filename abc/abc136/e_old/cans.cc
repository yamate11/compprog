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
  DLOG("prfac %lld", n);
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
  DLOG("prfac returns result.");
  return res;
}

vector<int> gdsub(int i, int n, auto fs) {
  if (i == n) { return vector<int>({1}); }
  auto part = gdsub(i+1, n, fs);
  int len = part.size();
  auto t = fs.at(i);
  ll p = t.first;
  ll r = t.second;
  ll pp = p;
  for (int m = 1; m <= r; m++) {
    for (int j = 0; j < len; j++) {
      part.push_back(pp * part.at(j));
    }
    pp *= p;
  }
  return part;
}

vector<int> getDivisors(int n) {
  auto primes = sieve(1e5);
  vector<pair<ll, ll>> fs = prfac(n, primes);
  return gdsub(0, fs.size(), fs);
}

bool allow(int N, int K, int d, auto A) {
  vector<int> r(N);
  for (int i = 0; i < N; i++) {
    r.at(i) = A.at(i) % d;
  }
  sort(r.begin(), r.end());
  int p = 0;
  int j = 0;
  for ( ; j < N && p + r.at(j) <= K; j++) p += r.at(j);
  int q = 0;
  int k = N-1;
  for ( ; k >= 0 && q + (d - r.at(k)) <= K; k--) q += d - r.at(k);
  return k < j;
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

  int N, K; cin >> N >> K;
  vector<int> A(N);
  int sum = 0;
  for (int i = 0; i < N; i++)  {
    cin >> A.at(i);
    sum += A.at(i);
  }
  vector<int> divisors = getDivisors(sum);
  sort(divisors.begin(), divisors.end(), greater<int>());
  for (int d : divisors) {
    if (allow(N, K, d, A)) {
      cout << d << endl;
      return 0;
    }
  }
  return 0;
}

