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

ll MOD = 1e9 + 7;

// g = eGCD(a, b, s, t)  --->  sa + tb = g
constexpr ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

constexpr ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(a, b, dummy1, dummy2);
}

struct Fp {
  ll val;

  Fp(ll t = 0) :
    val(t < 0 ? MOD + t % MOD : t >= MOD ? t % MOD : t) {}

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val > MOD) val -= MOD;
    return *this;
  }

  Fp& operator -=(const Fp& t) {
    val -= t.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Fp& operator *=(const Fp& t) {
    val = (val * t.val) % MOD;
    return *this;
  }

  Fp inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    ll u = 0;
    ll v = 0;
    eGCD(val, MOD, u, v);
    return Fp(u);
  }

  Fp& operator /=(const Fp& t) {
    return (*this) *= t.inv();
  }

  Fp operator +(const Fp& t) const { return Fp(val) += t; }
  Fp operator -(const Fp& t) const { return Fp(val) -= t; }
  Fp operator *(const Fp& t) const { return Fp(val) *= t; }
  Fp operator /(const Fp& t) const { return Fp(val) /= t; }
  Fp operator -() const { return Fp(-val); }

  bool operator ==(const Fp& t) const { return val == t.val; }
  bool operator !=(const Fp& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

ll N, K;
vector<vector<ll>> nbr;
vector<Fp> fact;
vector<Fp> invFact;

Fp perm(ll p, ll q) {
  if (p < q) return 0;
  return fact.at(p) * invFact.at(p-q);
}

Fp cnt(ll n, ll parent) {
  ll numC = nbr.at(n).size() - 1;
  Fp res = perm(K-2, numC);
  for (ll x : nbr.at(n)) {
    if (x == parent) continue;
    res *= cnt(x, n);
  }
  return res;
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

  cin >> N >> K;

  fact.resize(K+1);
  invFact.resize(K+1);
  fact.at(0) = 1;
  for (ll i = 1; i <= K; i++) fact.at(i) = i * fact.at(i-1);
  invFact.at(K) = fact.at(K).inv();
  for (ll i = K; i >= 1; i--) invFact.at(i-1) = i * invFact.at(i);
  
  nbr.resize(N+1);
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  ll numC2 = nbr.at(1).size();
  Fp res = K * perm(K-1, numC2);
  for (ll x : nbr.at(1)) {
    res *= cnt(x, 1);
  }
  cout << (ll)res << endl;

  return 0;
}

