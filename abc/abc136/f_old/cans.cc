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

ll MOD = 998244353;

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

template <class T>
class BIT {
  int size; // the number of slots
  vector<T> vec; // from 1 to size

public:

  BIT(int s) : size(s), vec(s+1) {}

  void add(int i, T x) {
    while (i <= size) {
      vec.at(i) += x;
      i += (i & (-i));
    }
  }

  T sum(int i) {
    T res = (T)0;
    while (i >= 1) {
      res += vec.at(i);
      i -= (i & (-i));
    }
    return res;
  }

};

template <class T>
void coordCompress(vector<T>& x) {
  int n = x.size();
  vector<T> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(),
       [&](int p, int q) { return x.at(p) < x.at(q); });
  T value = 0;
  for (int i = 0; i < n; i++) {
    T nextValue = (i+1 < n && x.at(ord.at(i)) != x.at(ord.at(i+1)))
                  ? value + 1 : value;
    x.at(ord.at(i)) = value;
    value = nextValue;
  }
}

vector<Fp> pow2;
void fillPow(int N) {
  pow2.resize(N+1);
  pow2.at(0) = 1;
  for (int i = 1; i <= N; i++) {
    pow2.at(i) = pow2.at(i-1) * (Fp)2;
  }
}
Fp pow(int n) { return pow2.at(n); }

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

  DLOG("1");

  int N; cin >> N;
  vector<int> x(N), y(N), col(N), row(N), aCol(N+1), ord(N);
  for (int i = 0; i < N; i++) {
    int xx, yy; cin >> xx >> yy;
    x.at(i) = xx;
    y.at(i) = yy;
  }
  DLOG("1.5");
  coordCompress(x);
  coordCompress(y);

  DLOG("2");
  
  for (int i = 0; i < N; i++) {
    col.at(x.at(i))++;
    row.at(y.at(i))++;
  }
  for (int i = 1; i <= N; i++)  aCol.at(i) = aCol.at(i-1) + col.at(i-1); 
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(),
       [&](int p, int q) {
	 if (y.at(p) == y.at(q)) return x.at(p) < x.at(q);
	 else return y.at(p) < y.at(q);
       });
  BIT<int> t(N);

  fillPow(N);

  DLOG("3");
  
  int cl = 0;
  Fp ans = (Fp)0;
  for (int k = 0; k < N; k++) {
    int i = ord.at(k);
    int xi = x.at(i);
    int yi = y.at(i);
    int ul = xi == 0 ? 0 : t.sum(xi);
    int uc = t.sum(xi + 1) - ul;
    int ur = k == 0 ? 0 : k - (ul + uc);
    {
      if (k == 0 || yi > y.at(ord.at(k-1))) cl = 0;
      else cl++;
    }
    int cr = row.at(yi) - (cl + 1);
    int dl = aCol.at(xi) - ul;
    int dc = col.at(xi) - (uc + 1);
    int dr = N - (aCol.at(xi + 1) + ur + cr);

    t.add(xi + 1, 1);

    ans += pow(N)
      - (pow(ul+cl+dl) + pow(ur+cr+dr) + pow(ul+uc+ur) + pow(dl+dc+dr))
      + (pow(ul) + pow(ur) + pow(dl) + pow(dr))
      - (Fp)1;  // empty
      
  }

  DLOG("4");
  

  cout << (int)ans << endl;

  return 0;
}

