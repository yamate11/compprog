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


ll N, M;
vector<vector<ll>> nbr;
ll S, T;

ll enc(ll level, ll i) { return level * N + (i-1); }
ll nl(ll level) { return (level + 1) % 3; }


int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
#endif
  cout << setprecision(20);

  cin >> N >> M;
  nbr.resize(3*N);
  for (ll i = 0; i < M; i++) {
    ll u, v;  cin >> u >> v;
    for (ll level = 0; level < 3; level++) {
      nbr.at(enc(level, u)).push_back(enc(nl(level), v));
    }
  }
  cin >> S >> T;

  vector<Fp> vfp(10);
  vfp.at(0) = Fp(10);
  vfp.at(1) = Fp(-3);
  

  vector<ll> dist(3*N, -1);
  vector<bool> done(3*N);
  queue<ll> que;
  dist.at(enc(0, S)) = 0;
  que.push(enc(0, S));
  while (!que.empty()) {
    ll x = que.front(); que.pop();
    DLOG("qtop = %lld", x);
    if (done.at(x)) continue;
    for (ll y : nbr.at(x)) {
      if (dist.at(y) >= 0) continue;
      dist.at(y) = dist.at(x) + 1;
      que.push(y);
    }
    done.at(x) = true;
  }
  ll z = dist.at(enc(0, T));
  ll ans = z < 0 ? -1 : z / 3;
  cout << ans << endl;

  return 0;
}

