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
// ----------------------------------------------------------------------

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

class Comb {
  int nMax;
  vector<Fp> vFact;
  vector<Fp> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  Fp fact(int n) { return vFact.at(n); }
  Fp comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  Fp perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

// Returns a const char* representation of a container, such as a vector.
// Works for a container whose iterator has begin() and end()
// E.g.
//       vector<ll> v = {1, 2, 3};
//       DLOG("v = %s", toString(v).c_str());    // You need c_str()  
string toString(auto v) {
  stringstream ss;
  ss << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin())  ss << ", ";
    // if the value_type is not printable, modify the following line.
    ss << *it;
    // e.g., if it is a pair, use "ss << pairToString(*it)"
  }
  ss << "]";
  return ss.str();
}

string pairToString(auto p) {
  stringstream ss;
  ss << "(" << p.first << ":" << p.second << ")";
  return ss.str();
}


// Converts a container that has top(), pop() and empty() into a vector.
// Unfortunately, container_type need to be fixed.  In below, it is ll.
vector<ll> toVector(auto q)
{
  vector<ll> v;
  while (!q.empty()) {
    v.push_back(q.top());
    q.pop();
  }
  return v;
}

// ----------------------------------------------------------------------
int toIdx (char c) {
  if (c == 'R') return 0;
  if (c == 'G') return 1;
  if (c == 'B') return 2;
  assert(false);
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

  int N; cin >> N;
  string S; cin >> S;

  vector<int> appear(3);
  vector<int> rank(3, 1);

  auto getAbove = [&](int x) -> int {
    assert(x == 2 || x == 3);
    for (int i = 0; i < 3; i++) {
      if (rank.at(i) + 1 == x) return i;
    }
    assert(x == 3);
    for (int i = 0; i < 3; i++) {
      if (rank.at(i) == 1) return i;
    }
    assert(0);
  };

  Fp ans = 1;
  for (int i = 0; i < 3*N; i++) {
    int c = toIdx(S.at(i));
    if (rank.at(c) == 1) {
      ans *= Fp(N - appear.at(c));
      for (int j = 0; j < 3; j++) {
	if (c == j) continue;
	if (rank.at(j) == 1) rank.at(j) = 2;
      }
    }else if (rank.at(c) == 2) {
      int d = getAbove(2);
      int diff = appear.at(d) - appear.at(c);
      ans *= Fp(diff);
      if (diff == 1) rank.at(c) = 1;
      for (int j = 0; j < 3; j++) {
	if (c == j) continue;
	if (rank.at(j) == 2) rank.at(j) = 3;
      }
    }else if (rank.at(c) == 3) {
      int d = getAbove(3);
      int diff = appear.at(d) - appear.at(c);
      ans *= Fp(diff);
      if (diff == 1) rank.at(c) = rank.at(d);
    }else assert(false);

    appear.at(c) += 1;
    
    DLOG("ans = %d", ans);
    DLOG("appear = %s", toString(appear).c_str());    // You need c_str()  
    DLOG("rank = %s", toString(rank).c_str());    // You need c_str()  

  }
  cout << (int)ans << endl;

  return 0;
}

