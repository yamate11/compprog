#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mod power)

template<int mod> void testf1(int dyn_mod);

int main() {

  {
    auto [t13, t11, t12] = eGCD(15, 20);
    assert(t13 == 5 && t13 == 15 * t11 + 20 * t12);
    assert(gcd(1,7) == 1);
    assert(gcd(8, 2) == 2);
  }

  testf1<7>(0);
  testf1<0>(7);

  {
    using Fp = FpG<7>;
    vector<Fp> v01(10);
    for (int i = 0; i < 10; i++) v01.at(i) = power(Fp(3), i);
    assert(v01 == vector<Fp>({Fp(1), Fp(3), Fp(2), Fp(6), Fp(4), Fp(5),
	    Fp(1), Fp(3), Fp(2), Fp(6)}));
    assert(power(2, 0) == 1);
    assert(power(2, 15) == 32768);
    assert(power(2, 16) == 65536);
  }

  {
    using Fp = FpG<7>;
    Fp z1(5);
    Fp z2(100);
    Fp z3(z2);
    assert(z3.val == 2);
    Fp z4(0);
    z4 = z1;
    assert(z4.val == 5);
    Fp z5(0);
    z5 = -8;
    assert(z5.val == 6);
    Fp z6 = LLONG_MAX;
    assert(z6.val == LLONG_MAX % 7);
    for (int i = 30; i < 37; i++) {
      for (int j = -50; i < -43; j++) {
	assert(Fp(i) + Fp(j) == i + Fp(j));
	assert(Fp(i) * Fp(j) == Fp(i) * j);
	assert(Fp(i) - Fp(j) == i - Fp(j));
	if (Fp(j) != Fp(0)) {
	  assert(Fp(i) / Fp(j) == Fp(i) / j);
	}
      }
    }
    stringstream ss1;
    ss1 << Fp(-9);
    assert(ss1.str() == "5");
    stringstream ss2("10");
    Fp xx; ss2 >> xx;
    assert(xx == Fp(3));
  }

  {
    using Fp = FpG<97>;
    Comb<Fp> cb(6);
    assert(cb.fact(4) == Fp(24));
    assert(cb.perm(5,3) == Fp(60));
    assert(cb.binom(6,2) == Fp(15));
    assert(cb.binom(6,4) == Fp(15));
    assert(cb.binom(6,-1) == Fp(0));
    assert(cb.binom(6,7) == Fp(0));
    assert(cb.binom_dup(2, 4) == Fp(5));

    Comb<double> cb2(8);
    assert(cb2.fact(8) == 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1);
    assert(cb2.binom(7, 3) == 7 * 6 * 5 / 3 / 2 / 1);

  }

  {
    using Fp = FpG<100>;
    Fp a = Fp(50) / Fp(7); // should be OK
    try {
      if (a != Fp(50) / Fp(75));  // should generate a runtime error as (75, 100) != 1
      cerr << "Should not reach here." << endl;
      assert(0);
    }catch(const runtime_error& e) {
      // as expected
    }
  }

  cout << "ok" << endl;
}

template<int mod>
void testf1(int dyn_mod) {
  using Fp = FpG<mod>;
  if (mod == 0) {
    Fp::setMod(dyn_mod);
  }
  assert(Fp(0).val == 0);
  assert(Fp(2).val == 2);
  assert(Fp(7).val == 0);
  assert(Fp(74).val == 4);
  assert(Fp(-4).val == 3);
  assert(Fp(-7).val == 0);
  assert(Fp(-8).val == 6);
  assert(Fp(-14).val == 0);
  assert(Fp(-16).val == 5);
  Fp x;
  assert((ll)x == 0);
  assert(x == Fp(0));
  assert(Fp(2) == Fp(-5));
  assert(Fp(2) != Fp(-2));
  x = Fp(3);
  x += Fp(5);
  assert(x == Fp(1));
  x += Fp(6);
  assert(x == Fp(0));
  x = Fp(2);
  x -= Fp(5);
  assert(x == Fp(4));
  x -= Fp(4);
  assert(x == Fp(0));
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
  if (mod == 0) {
    assert(Fp::getMod() == dyn_mod);
  }else {
    assert(Fp::getMod() == mod);
  }
}

