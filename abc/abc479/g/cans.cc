#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(rational)

// ---- inserted library file rational.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/rational.cc

template<class T> string g_show(const T& x);

template<typename INT>
struct Rational {
  INT num;
  INT den;

  Rational(type_identity_t<INT> num_ = 0, type_identity_t<INT> den_ = 1) : num(num_), den(den_) { reduction(); }
  void reduction() {
    if (den == 0) { throw runtime_error("Rational.reduction: division by zero"); }
    if (den < 0) {
      num = -num;
      den = -den;
    }
    INT g = gcd(num, den);
    num /= g;
    den /= g;
  }

  bool operator==(const Rational& o) const = default;
  strong_ordering operator<=>(const Rational& o) const {
    INT g = gcd(den, o.den);
    // return num * (o.den / g) <=> (den / g) * o.num;
    return num * (o.den / g) <=> (den / g) * o.num;
  }

  static Rational _add(const Rational& a, const Rational& b) {
    Rational ret;
    INT g = gcd(a.den, b.den);
    INT aa = a.den / g;
    INT bb = b.den / g;
    ret.num = a.num * bb + aa * b.num;
    ret.den = aa * b.den;
    ret.reduction();
    return ret;
  }
  static Rational _mult(const Rational& a, const Rational& b) {
    Rational ret;
    INT g1 = gcd(a.num, b.den);
    INT g2 = gcd(a.den, b.num);
    ret.num = (a.num / g1) * (b.num / g2);
    ret.den = (a.den / g2) * (b.den / g1);
    // need not call ret.reduction()
    return ret;
  }

  Rational operator+(const Rational& o) const { return _add(*this, o); }
  Rational operator-() const { return Rational(-num, den); }
  Rational operator-(const Rational& o) const { return *this + (-o); }
  Rational operator*(const Rational& o) const { return _mult(*this, o); }
  Rational inverse() const { return Rational(den, num); }
  Rational operator/(const Rational& o) const { return *this * o.inverse(); }
    
  Rational& operator+=(const Rational& o) { return *this = *this + o; }
  Rational& operator-=(const Rational& o) { return *this = *this - o; }
  Rational& operator*=(const Rational& o) { return *this = *this * o; }
  Rational& operator/=(const Rational& o) { return *this = *this / o; }

  friend Rational operator+(INT a, const Rational& b) { return Rational(a) + b; }
  friend Rational operator-(INT a, const Rational& b) { return Rational(a) - b; }
  friend Rational operator*(INT a, const Rational& b) { return Rational(a) * b; }
  friend Rational operator/(INT a, const Rational& b) { return Rational(a) / b; }

  // for debug
  string show() const { return g_show(num) + "/" + g_show(den); }

};



// ---- end rational.cc

// @@ !! LIM -- end mark --

using integer = __int128;
using Rat = Rational<integer>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  integer big = 1e18;

  ll N; cin >> N;

  auto f = [&](const auto& P, const auto& Q) -> Rat {
    vector<Rat> vec;
    REP(i, 0, N) {
      if (P[i] != 0) {
        Rat t(Q[i], P[i]);
        vec.emplace_back(t);
      }
    }
    if (vec.empty()) return Rat(big, 1);
    ranges::sort(vec);
    ll k = ssize(vec) / 2;
    integer sum = 0;
    REP(i, 0, N) {
      sum += abs(P[i] * vec[k].num - Q[i] * vec[k].den);
    }
    return Rat(sum, vec[k].den);
  };

  // @InpVec(N, A) [WnPay0SZ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [WnPay0SZ]
  // @InpVec(N, B) [hPgKLfxH]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [hPgKLfxH]

  auto p1 = f(A, B);
  auto p2 = f(B, A);
  integer aa = 0, bb = 0;
  REP(i, 0, N) aa += abs(A[i]);
  REP(i, 0, N) bb += abs(B[i]);
  auto ans = min(p1, min(p2, min(Rat(aa), Rat(bb))));
  cout << (ll)ans.num << " " << (ll)ans.den << "\n";

  return 0;
}

