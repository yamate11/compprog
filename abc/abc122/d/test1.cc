#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll MOD = 1e9 + 7;

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

int main() {
  MOD = 7;
  assert(Fp(0).val == 0);
  assert(Fp(2).val == 2);
  assert(Fp(74).val == 4);
  assert(Fp(-16).val == 5);
  Fp x;
  assert((ll)x == 0);
  assert(x == Fp(0));
  assert(Fp(2) == Fp(-5));
  assert(Fp(2) != Fp(-2));
  x = Fp(3);
  x += Fp(5);
  assert(x == Fp(1));
  x = Fp(2);
  x -= Fp(5);
  assert(x == Fp(4));
  x = Fp(6);
  x *= Fp(2);
  assert(x == Fp(5));
  assert(Fp(5).inv() == Fp(3));
  assert(Fp(5) == Fp(-4).inv());
  x = Fp(2);
  x /= Fp(3);
  assert(x == Fp(3));
  assert(Fp(10) + Fp(20) == Fp(2));
  assert(Fp(10) * Fp(-2) == Fp(1));
  assert(Fp(5) - Fp(8) == Fp(4));
  assert(Fp(4) / Fp(6) == Fp(3));
  assert(-Fp(4) == Fp(3));

  cout << "ok" << endl;
}
