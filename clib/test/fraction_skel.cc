#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

// @@ !! LIM(fraction)

template<typename Int>
bool wf(fraction<Int> f) { return f.den > 0 and gcd(f.num, f.den) == (Int)1; }

int main() {
  {
    using Frac = fraction<ll>;

    Frac xa;
    assert(xa.num == 0 and xa.den == 1);
    Frac xb(-5);
    assert(xb.num == -5 and xb.den == 1);
    Frac xc(2, 4);
    assert(xc.num == 1 and xc.den == 2);
    Frac xd(-18, -12);
    assert(xd.num == 3 and xd.den == 2);
    Frac xe(105, -30);
    assert(xe.num == -7 and xe.den == 2);
    Frac xf(xe);
    assert(xf.num == -7 and xf.den == 2);
    Frac xg;
    xg = xe;
    assert(xg.num == -7 and xg.den == 2);
    assert(Frac(1, -3) == Frac(-2, 6));
    assert(Frac(10, 1) != Frac(1, 10));
    Frac xh(2, -3);
    xh.self_negate();
    assert(xh.num == 2 and xh.den == 3);
    Frac xi = -xh;
    assert(xi.num == -2 and xi.den == 3);
    Frac xj(1, 10);
    xj += Frac(1);
    assert(wf(xj) and xj == Frac(11, 10));
    xj -= Frac(2);
    assert(wf(xj) and xj == Frac(-9, 10));
    Frac xk(-5, 7);
    xk *= Frac(2, -10);
    assert(wf(xk) and xk == Frac(1, 7));
    Frac xl(-5, 8);
    xl.self_inverse();
    assert(wf(xl) and xl == Frac(8, -5));
    Frac xm = xl.inverse();
    assert(wf(xm) and xm == Frac(-5, 8));
    Frac xn = Frac(4, 11);
    xn /= Frac(-8);
    assert(wf(xn) and xn == Frac(4, -88));
    Frac xo = Frac(4, 15) + Frac(-1, 15);
    assert(wf(xo) and xo == Frac(1, 5));
    Frac xp = Frac(4, 15) - Frac(4, 15);
    assert(xp.num == 0 and xp.den == 1);
    Frac xq = Frac(17, 15) + Frac(13, 15);
    assert(xq.num == 2 and xq.den == 1);
    Frac xr = Frac(4, 21) * Frac(-18, 11);
    assert(wf(xr) and xr == Frac(4 * (-18), 21 * 11));
    Frac xs = Frac(12, -5) / Frac(25, -2);
    assert(wf(xs) and xs == Frac(24, 125));
    assert(not Frac(1, -2).positive() and Frac(1, -2).negative() and not Frac(1, -2).is_zero());
    assert(Frac(-1, -2).positive() and not Frac(-1, -2).negative() and not Frac(-1, -2).is_zero());
    assert(not Frac(0).positive() and not Frac(0).negative() and Frac(0).is_zero());
    Frac xt = Frac(12, 25), xu = Frac(1, 2), xv = Frac(-2, 1), xw = Frac(2, -1);
    assert(xt < xu and xt <= xu and not (xt > xu) and not (xt >= xu));
    assert(xv < xu and xv <= xu and not (xv > xu) and not (xv >= xu));
    assert(not (xv < xw) and xv <= xw and not (xv > xw) and xv >= xw);
    assert(abs(Frac(-2, 7)) == Frac(2, 7) and abs(Frac(11, 4)) == Frac(11, 4));
    stringstream ss;
    ss << Frac(1, 2) << " " << Frac(3, -4);
    assert(ss.str() == "frac(1, 2) frac(-3, 4)");
  }
  {
    using Frac = fraction<cpp_int>;
    Frac xa(3);
    REP(i, 0, 100) xa *= cpp_int(5);
    REP(i, 0, 50) xa /= cpp_int(25);
    assert(xa == cpp_int(3));
    cpp_int t100 = 1;;
    REP(i, 0, 100) t100 *= 10;
    Frac xb(1, 3 * t100);
    Frac xc(1, 4 * t100);
    Frac xd = xb + xc;
    assert(xd.num == 7 and xd.den == 12 * t100);
    Frac xe = xc - xb;
    assert(xe.num == -1 and xe.den == 12 * t100);
    Frac xf = xb * xc;
    assert(xf == Frac(1, 12 * t100 * t100));
    Frac xg = xb / xc;
    assert(xg == Frac(4, 3));
  }

  return 0;
}

