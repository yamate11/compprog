#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>

// @@ !! LIM(f:perfmeas)

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

constexpr ll safeMod(ll v, ll p) {
  if (v >= 0) return v % p;
  else        return p + (v % p);
}

template<int st_p>
struct modint {
  ll _v;
  static int prime;
  
  modint() : _v(0) {}
  modint(ll v): _v(residue(v)) {}

  int residue(ll v) {
    if (st_p) return safeMod(v, st_p);
    else      return safeMod(v, prime);
  }

  modint& operator +=(const modint& o) {
    _v = residue(_v + o._v);
    return *this;
  }
  modint& operator *=(const modint& o) {
    _v = residue(_v * o._v);
    return *this;
  }
};
template<int st_p>
int modint<st_p>::prime = 0;

template<int st_p>
struct static_modint {
  ll _v;
  
  static_modint() : _v(0) {}
  static_modint(ll v): _v(residue(v)) {}

  constexpr int residue(ll v) {
    return safeMod(v, st_p);
  }

  static_modint& operator +=(const static_modint& o) {
    // _v += o._v;
    // if (_v >= st_p) _v -= st_p;
    _v = residue(_v + o._v);
    return *this;
  }
  static_modint& operator *=(const static_modint& o) {
    _v = residue(_v * o._v);
    return *this;
  }
};

constexpr int prime17 = 1'000'000'007;
constexpr int prime93 = 998'244'353;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using Tx = modint<0>;
  using Tz = modint<prime93>;
  using Ty = static_modint<prime17>;
  Tx::prime = prime17;

  Tx x;
  Ty y;
  Tz z;

  int logrep = atoi(argv[1]);
  int seed1 = atoi(argv[2]);
  int seed2 = atoi(argv[3]);
  ll rep = 1LL << logrep;

  Tx x_seed1(seed1);
  Ty y_seed1(seed1);
  Tz z_seed1(seed1);
  Tx x_seed2(seed2);
  Ty y_seed2(seed2);
  Tz z_seed2(seed2);
  
  double t0 = get_time_sec();
  for (ll i = 0; i < rep / 100; i++) {
    x *= x_seed1;
    x += x_seed2;
  }
  for (ll i = 0; i < rep / 100; i++) {
    z *= z_seed1;
    z += z_seed2;
  }
  for (ll i = 0; i < rep / 100; i++) {
    y *= y_seed1;
    y += y_seed2;
  }

  double t1 = get_time_sec();
  for (ll i = 0; i < rep; i++) {
    x *= x_seed1;
    x += x_seed2;
  }
  double t2 = get_time_sec();
  for (ll i = 0; i < rep; i++) {
    y *= y_seed1;
    y += y_seed2;
  }
  double t3 = get_time_sec();
  for (ll i = 0; i < rep; i++) {
    z *= z_seed1;
    z += z_seed2;
  }
  double t4 = get_time_sec();
  for (ll i = 0; i < rep; i++) {
    z *= z_seed1;
    z += z_seed2;
  }
  double t5 = get_time_sec();
  for (ll i = 0; i < rep; i++) {
    y *= y_seed1;
    y += y_seed2;
  }
  double t6 = get_time_sec();
  cout << x._v << " " << y._v << " " << z._v << endl;
  cout << t1 - t0 << endl;
  cout << t2 - t1 << endl;
  cout << t3 - t2 << endl;
  cout << t4 - t3 << endl;
  cout << t5 - t4 << endl;
  cout << t6 - t5 << endl;

  return 0;
}

