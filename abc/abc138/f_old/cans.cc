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
    if (val >= MOD) val -= MOD;
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

vector<char> tobin(ll x) {
  vector<char> res;
  while (x > 0) {
    res.push_back(x & 1);
    x >>= 1;
  }
  return res;
}



int enc(int i, bool neR, bool neL) {
  return 4*i + 2*neR + neL;
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

  ll L, R; cin >> L >> R;
  vector<char> bL = tobin(L);
  vector<char> bR = tobin(R);
  int szL = bL.size();
  int szR = bR.size();

  vector<Fp> dp(4*(szR+1));
  for (int i = szR-1; i >= 0; i--) {

    if (i >= szL-1) dp.at(enc(i, i != szR-1, i != szL-1)) += 1;
    
    {
      Fp n = dp.at(enc(i+1, false, false));  // n == 0 or 1
      int rr = bR.at(i);
      int ll = i < szL ? bL.at(i) : 0;
      if (rr == ll) {
	dp.at(enc(i, false, false)) += n;
      }else if (rr == 1 && ll == 0) {
	dp.at(enc(i, false, false)) += n;
	dp.at(enc(i, true, false)) += n;
	dp.at(enc(i, false, true)) += n;
      }else { // rr == 0 && ll == 1
	// cannot continue
      }
    }
    {
      Fp n = dp.at(enc(i+1, true, false));
      if (i < szL && bL.at(i) == 1) {
	dp.at(enc(i, true, false)) += n;
      }else {
	dp.at(enc(i, true, false)) += 2 * n;
	dp.at(enc(i, true, true))  += n;
      }
    }
    {
      Fp n = dp.at(enc(i+1, false, true));
      if (bR.at(i) == 0) {
	dp.at(enc(i, false, true)) += n;
      }else {
	dp.at(enc(i, false, true)) += 2 * n;
	dp.at(enc(i, true, true))  += n;
      }
    }
    {
      Fp n = dp.at(enc(i+1, true, true));
      dp.at(enc(i, true, true)) += 3 * n;
    }

  }

  Fp s = 0;
  for (int neR = 0; neR < 2; neR++) {
    for (int neL = 0; neL < 2; neL++) {
      s += dp.at(enc(0, neR, neL));
    }
  }
  cout << (int)s << endl;

  return 0;
}

