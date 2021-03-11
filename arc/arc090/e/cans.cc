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

ll MOD = 1e9 + 7;
// ll MOD = 998244353;

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

/* 
   Power function    power(a, b) == a^b
   Speed is O(log b).
   The same source code can be used for integers by replacing
   Fp with int etc.  Unfortunately, replacing Fp with auto does not
   make the function generic for int and Fp.
 */
Fp power(Fp a, int b) {
  Fp twoPow = a;
  Fp rv = 1;
  while (b > 0) {
    if (b & 1) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}

template<typename F>
class FixPoint : private F {
public:
  explicit constexpr FixPoint(F&& f) noexcept : F(forward<F>(f)) {}

  template<typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template<typename F>
static inline constexpr decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}

// ----------------------------------------------------------------------
struct Peer {
  int idx;
  int len;
  Peer(int _idx, int _len) : idx(_idx), len(_len) {}
};

struct Dij {
  int idx;
  ll dist;
  Dij(int i, ll d) : idx(i), dist(d) {}
};

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

  int N, M, S, T; cin >> N >> M >> S >> T; S--; T--;
  vector<vector<Peer>> nbr(N);
  for (int i = 0; i < M; i++) {
    int u, v, d; cin >> u >> v >> d; u--; v--;
    nbr.at(u).emplace_back(v, d);
    nbr.at(v).emplace_back(u, d);
  }
  
  vector<ll> distS(N, LLONG_MAX);
  auto comp = [](Dij x, Dij y) { return x.dist > y.dist; };
  priority_queue<Dij, vector<Dij>, decltype(comp)> pque(comp);
  pque.push(Dij(S, 0));
  while (!pque.empty()) {
    Dij dij = pque.top(); pque.pop();
    if (distS.at(dij.idx) <= dij.dist) continue;
    distS.at(dij.idx) = dij.dist;
    for (Peer p : nbr.at(dij.idx)) {
      if (dij.dist + p.len < distS.at(p.idx)) {
	pque.push(Dij(p.idx, dij.dist + p.len));
      }
    }
  }
  ll distST = distS.at(T);

  vector<vector<int>> toS(N), toT(N);
  auto setRoute = fix([&](auto recF, int idx) -> void {
      if (toS.at(idx).size() > 0) return;
      for (Peer p : nbr.at(idx)) {
	if (distS.at(p.idx) + p.len != distS.at(idx)) continue;
	toS.at(idx).push_back(p.idx);
	toT.at(p.idx).push_back(idx);
	recF(p.idx);
      }
    });
  setRoute(T);

  vector<Fp> numRouteS(N), numRouteT(N);
  vector<bool> doneS(N), doneT(N);
  numRouteS.at(S) = numRouteT.at(T) = 1;
  doneS.at(S) = doneT.at(T) = true;
  auto countRoute =
    fix([&](auto recF, int i, auto& tog, auto& numR, auto& done) -> Fp {
	if (done.at(i)) return numR.at(i);
	done.at(i) = true;
	Fp sum = 0;
	for (int j : tog.at(i)) sum += recF(j, tog, numR, done);
	numR.at(i) = sum;
	return sum;
      });
  countRoute(T, toS, numRouteS, doneS);
  countRoute(S, toT, numRouteT, doneT);

  Fp totNumRoute = numRouteS.at(T) * numRouteT.at(S);
  Fp meetNumRoute = Fp(0);
  for (int i = 0; i < N; i++) {
    if (2 * distS.at(i) > distST) continue;
    else if (2 * distS.at(i) == distST) {
      Fp x = numRouteS.at(i) * numRouteT.at(i);
      meetNumRoute += x * x;
    }else {
      for (int j : toT.at(i)) {
	if (2 * distS.at(j) <= distST) continue;
	Fp x = numRouteS.at(i) * numRouteT.at(j);
	meetNumRoute += x * x;
      }
    }
  }
  cout << int(totNumRoute - meetNumRoute) << endl;

  return 0;
}

