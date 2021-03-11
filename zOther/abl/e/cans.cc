#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define CONSTANT_MOD 998244353

// @@ !! LIM(mod)
// --> f:gcd f:intDiv mod
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
ll eGCD(ll a, ll b, ll& s, ll& t) {
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

// gcd(0, x) = x, gcd(-x, y) = gcd(x, y)
ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(abs(a), abs(b), dummy1, dummy2);
}

// Chinese Remainder Theorem
//    auto [r, z] = crt(x1, a1, x2, a2)
//    ==>   r = a1 (mod x1);  r = a2 (mod x2);  z = lcm(x1, x2);  0 <= r < z
//    If no such r exists, returns [-1, -1]
//    Note: x1 and x2 should be >= 1.  a1 and a2 can be negative or zero.
pair<ll, ll> crt(ll x1, ll a1, ll x2, ll a2) {
  ll s, t; ll g = eGCD(x1, x2, s, t);
  if (a1 % g != 0 || a2 % g != 0) return {-1, -1};
  ll z = x1 / g * x2;
  ll p = (a2 / g) * s * x1 + (a1 / g) * t * x2;
  ll r = p % z;
  if (r < 0) r += z;
  return {r, z};
};

// ---- end gcd
// ---- inserted function intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}

// ---- end intDiv
// ---- inserted library file mod.cc

/*
  You may want to put something like:
#define CONSTANT_MOD (1e9 + 7)
#define CONSTANT_MOD 998244353
  in the header part (outside of library paste area)
 */

struct Fp {
#if defined(CONSTANT_MOD)
  static const ll MOD = CONSTANT_MOD;
#else
  static ll MOD;
#endif

  ll val;

  /*
  ll _calc_from_ll(ll t = 0) {
    if      (t >= MOD)  return t % MOD;
    else if (t >= 0)    return t;
    else if (t >= -MOD) return t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) return 0;
      else        return v + MOD;
    }
  }
  */

  Fp(ll t = 0) : val(imod(t, MOD)) {}
  Fp(const Fp& t) : val(t.val) {}
  Fp& operator =(const Fp& t) { val = t.val; return *this; }
  Fp& operator =(ll t) { val = imod(t, MOD); return *this; }
  Fp& operator =(int t) { val = imod(t, MOD); return *this; }

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

Fp operator +(int x, const Fp& y) { return Fp(x) + y; }
Fp operator -(int x, const Fp& y) { return Fp(x) - y; }
Fp operator *(int x, const Fp& y) { return Fp(x) * y; }
Fp operator /(int x, const Fp& y) { return Fp(x) / y; }
Fp operator +(ll x, const Fp& y) { return Fp(x) + y; }
Fp operator -(ll x, const Fp& y) { return Fp(x) - y; }
Fp operator *(ll x, const Fp& y) { return Fp(x) * y; }
Fp operator /(ll x, const Fp& y) { return Fp(x) / y; }
Fp operator +(const Fp& x, int y) { return x + Fp(y); }
Fp operator -(const Fp& x, int y) { return x - Fp(y); }
Fp operator *(const Fp& x, int y) { return x * Fp(y); }
Fp operator /(const Fp& x, int y) { return x / Fp(y); }
Fp operator +(const Fp& x, ll y) { return x + Fp(y); }
Fp operator -(const Fp& x, ll y) { return x - Fp(y); }
Fp operator *(const Fp& x, ll y) { return x * Fp(y); }
Fp operator /(const Fp& x, ll y) { return x / Fp(y); }

istream& operator>> (istream& is, Fp& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Fp& t) {
  os << t.val;
  return os;
}

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

#if !defined(CONSTANT_MOD)
// ll Fp::MOD = 1e9 + 7;
// ll Fp::MOD = 998'244'353;
#endif

// ---- end mod.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;

  // tenp     .. power of ten
  // acc_tenp .. accumulating sum of power of ten
  vector<Fp> tenp(N), acc_tenp(N+1);
  for (ll i = 0; i < N; i++) {
    if (i == 0) tenp[0] = 1;
    else tenp[i] = tenp[i-1] * 10;
    acc_tenp[i+1] = acc_tenp[i] + tenp[i];
  }

  // value of "ddd..d00..0", where d starts at pos1 (from right,
  // inclusive) and ends at pos2 (from right, not inclusive).
  auto valseq = [&](ll d, ll pos1, ll pos2) -> Fp {
    return acc_tenp[pos2 - pos1] * d * tenp[pos1];
  };

  // a map representing the step function
  map<ll, ll> mp;
  mp[-1] = 0;   // a sentinel
  mp[0] = 1;
  mp[N] = 0;    // a sentinel
  
  // Adds a redundant element (t, f(t)) to the map,
  // and returns an iterator for the element.
  auto add_red = [&](ll t) {
    auto it = mp.lower_bound(t);
    if (t == it->first) return it;
    auto rit = reverse_iterator(it);
    auto [ret_it, dummy] = mp.insert_or_assign(t, rit->second);
    return ret_it;
  };

  Fp tot = acc_tenp[N];  // total sum
  for (ll _q = 0; _q < Q; _q++) {
    ll xl, xr, dNew; cin >> xl >> xr >> dNew;
    ll l = N - xr;       // left boundary, inclusive
    ll r = N - xl + 1;   // right boundary, NOT inclusive

    auto itL = add_red(l);
    auto itR = add_red(r);
    Fp sum = 0;   // the current sum between l and r
    {
      auto it = itL;
      while (true) {
	auto nit = it; nit++;
	Fp z = valseq(it->second, it->first, nit->first);
	sum += z;
	if (nit == itR) break;
	it++;
      }
    }
    Fp added = valseq(dNew, l, r);
    tot += added - sum;
    cout << tot << "\n";

    // Set the new value at l
    itL->second = dNew;

    // Remove all points between l and r.
    {
      auto it = itL; it++;
      while (it != itR) it = mp.erase(it);
    }

  }

  return 0;
}

