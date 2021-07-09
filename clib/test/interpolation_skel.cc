#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(debug interpolation)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  if (0) {
    using Pol = Polynomial<FpA, 0>;
    vector<FpA> v = {-5, 7, -47, 203, -919, 4163, -18815, 85099, -384839, 1740371};
    auto optsol = fitFPS<Pol>(v, 3);
    if (optsol) cout << "OK\n";
    else cout << "NG\n";

    return 0;
  }

  {// aising2020 F - Two Snuke
    using Pol = Polynomial<double, 0>;
    ll N = 50;
    vector<double> A(2*N);
    for (ll s1 = 0; s1 < N; s1++) {
      for (ll s2 = s1 + 1; s2 < N; s2++) {
        A[s1 + s2] += s2 - s1;
      }
    }
    auto optsol = fitFPS<Pol>(A, 10);
    assert(optsol);
    auto [p, q] = *optsol;
    assert(p == Pol({0, 1}));
    assert(q == Pol({1, -2, 0, 2, -1}));
  }

  {
    // using Pol = Polynomial<double, 0>;
    // using Fp = double;
    using Pol = Polynomial<FpA, 0>;
    using Fp = FpA;
    
    ll rep = 1000;
    ll deglim = 10;
    for (ll _r = 0; _r < rep; _r++) {
      ll deg_q = randrange(1, deglim);
      ll deg_p = randrange(0, deg_q);
      vector<Fp> vq;
      vq.push_back(1);
      for (ll i = 1; i <= deg_q; i++) vq.push_back(randrange(-9, 10));
      if (vq[deg_q] == 0) vq[deg_q] = randrange(1, 10);
      vector<Fp> vp;
      for (ll i = 0; i <= deg_p; i++) vp.push_back(randrange(-9, 10));
      if (vp[deg_p] == 0) vp[deg_p] = randrange(1, 10);
      Pol p(vp);
      Pol q(vq);
      Pol a = p.divFPS(Pol::SP(q), 3 * deglim);
      auto optsol = fitFPS<Pol>(a.coefVec(), deglim);
      assert(optsol);
      auto [p1, q1] = *optsol;
      assert(p * q1 == p1 * q);
    }
  }

  {
    using Pol = PolyFpA;
    vector<FpA> vs = {1, 2, 9, 28};
    Pol p = lagrangePol<Pol>(vs);
    assert(p == Pol({1, 0, 0, 1}));
  }

  {
    using Pol = PolyFpA;
    using Fp = FpA;
    
    // ll rep = 100000;
    ll rep = 1000;
    for (ll _r = 0; _r < rep; _r++) {
      ll deg = randrange(1, 10);
      vector<Fp> coef(deg + 1);
      for (ll i = 0; i < deg; i++) {
        coef[i] = randrange(0, primeA);
      }
      coef[deg] = randrange(1, primeA);
      Pol p(coef);
      vector<Fp> val(deg + 1);
      for (ll i = 0; i <= deg; i++) {
        assert(val[i] = p.atval(i));
      }
      Pol q = lagrangePol<Pol>(val);
      assert(p == q);
      for (ll i = 0; i < 10; i++) {
        Fp x = randrange(0, primeA);
        assert(lagrangeVal(val, x) == p.atval(x));
      }
    }
  }

  {
    using Fp = FpG<11>;
    auto f = [&](Fp x) -> Fp { return x*x*x*x + 4*x*x*x - 2*x*x + 5; };
    vector<Fp> vec;
    for (ll i = 0; i <= 4; i++) vec.push_back(f(i));
    for (ll i = 0; i < 30; i++) {
      assert(lagrangeVal(vec, i) == f(i));
    }
  }

  cout << "ok" << endl;

  return 0;
}


