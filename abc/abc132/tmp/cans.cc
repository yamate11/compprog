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
vector<vector<Fp>> vecA;
vector<vector<Fp>> vecB;

int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N >> K;
  ll rB = sqrt(N);
  ll rA = N / rB;

  vecA.resize(K+2);
  vecB.resize(K+2);
  for (ll k = 0; k <= K+1; k++) {
    vecA.at(k).resize(rA + 1);
    vecB.at(k).resize(rB);
  }
  vecA.at(0).at(1) = 1;
  for (ll k = 1; k <= K+1; k++) {
    vector<Fp> sumA(rA + 1);
    vector<Fp> sumB(rB + 1);
    for (ll i = 1; i <= rA; i++) {
      sumA.at(i) = sumA.at(i-1) + vecA.at(k-1).at(i);
    }
    for (ll i = rB-1; i >= 1; i--) {
      sumB.at(i) = sumB.at(i+1) + vecB.at(k-1).at(i);
    }
    for (ll i = 1; i <= rA; i++) {
      vecA.at(k).at(i) = sumA.at(min(N / i, rA)) + sumB.at(min(rB, i));
    }
    for (ll i = 1; i < rB; i++) {
      vecB.at(k).at(i) = sumA.at(i) * Fp((N / i) - (N / (i+1)));
    }
  }
  cout << vecA.at(K+1).at(1) << endl;

  return 0;
}

