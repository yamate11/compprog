#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< mod debug f:perfmeas polynomial)

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

  double et = get_time_sec();

  {
    using PolyDouble = Polynomial<double, 0>;

    PolyLL p1({-2, 0, 1});
    PolyLL p2({2, -1, 3, 2});

    assert(p1 == p1);
    assert(p1 != p2);

    assert(p1.degree() == 2 && p2.degree() == 3);
    assert(p1.coef[0] == -2 && p1.coef[1] == 0 && p1.coef[2] == 1);

    assert(p1 + p2 == PolyLL({0, -1, 4, 2}));
    assert(p2 + p1 == PolyLL({0, -1, 4, 2}));
    assert(p1 - p2 == PolyLL({-4, 1, -2, -2}));
    assert(p2 - p1 == PolyLL({4, -1, 2, 2}));
    assert(-p1 == PolyLL({2, 0, -1}));
    assert(PolyDouble(12.3) ==
           PolyDouble({12.3, 1.0}) - PolyDouble({0.0, 1.0}));
    PolyLL p3({1, 2, 3});
    PolyLL p4(p3);
    p3 *= PolyLL({0, 0, 0, 1});
    p4 += p3;
    assert(p4 == PolyLL({1, 2, 3, 1, 2, 3}));
    
    PolyLL p5({-4, 2, -4, -5, 3, 2});
    assert(p1 * p2 == p5);
    assert(p2 * p1 == p5);

    assert(10LL + p1 == PolyLL({8, 0, 1}));
    assert(p1 + 10LL == PolyLL({8, 0, 1}));
    assert(10LL - p1 == PolyLL({12, 0, -1}));
    assert(p1 - 10LL == PolyLL({-12, 0, 1}));
    assert(10LL * p1 == PolyLL({-20, 0, 10}));
    assert(p1 * 10LL == PolyLL({-20, 0, 10}));

    for (ll x = -3; x <= 3; x++) {
      assert(p2.atval(x) == 2 + (-1) * x + 3 * x*x + 2 * x*x*x);
    }

    auto X = PolyLL::get_X();
    assert((X - 1LL) * (X - 1LL) == (X * X) - 2LL * X + 1LL);

    Fp::MOD = 2;
    auto Y = Polynomial<Fp, 0>::get_X();
    assert((Y - Fp(1)) * (Y - Fp(1)) == (Y * Y) + Fp(1));

  }
  cerr << "1 " << get_time_sec() - et << endl;
  et = get_time_sec();
  {
    Fp::MOD = 1e9 + 7;
    using Pol = Polynomial<Fp, 0>;
    Pol p1;
    assert(p1.degree() == 0 && p1.coef[0] == Fp(0));
    Pol p2(Fp(10));
    assert(p2.degree() == 0 && p2.coef[0] == Fp(10));
    vector<Fp> v1({2, 3, 4});
    auto v2(v1);
    Pol p3(v1);
    Pol p4(move(v2));
    Pol p5({2, 3, 4});
    assert(p3 == p4 && p3 == p5 && !(p4 != p5));
    Pol p6(p3);
    Pol p7(move(p5));
    Pol p8; p8 = p3;
    Pol p9; p9 = move(p4);
    assert(p6 == p7 && p6 == p8 && p6 == p9);
    Pol p10; p10 = Fp(10);
    assert(p10 == p2);

    vector<Fp> v3({1, 2, 3, 4, 5});
    Pol p11(v3);
    Pol p11cp(p11);
    Pol p12({6, 7});
    p11 = p11cp; p11 += p12; assert(p11 == p11cp + p12);
    p11 = p11cp; p11 -= p12; assert(p11 == p11cp - p12);
    p11 = p11cp; p11 *= p12; assert(p11 == p11cp * p12);
    p11 = p11cp; p11 += Fp(10); assert(p11 == p11cp + Fp(10));
    p11 = p11cp; p11 -= Fp(10); assert(p11 == p11cp - Fp(10));
    p11 = p11cp; p11 *= Fp(10); assert(p11 == p11cp * Fp(10));
    p11 = p11cp; 
    assert(p11 + Fp(10) == Fp(10) + p11);
    assert(p11 - Fp(10) == -(Fp(10) - p11));
    assert(p11 * Fp(10) == Fp(10) * p11);

    stringstream ss;
    ss << p11;
    assert(ss.str() == "[1, 2, 3, 4, 5]");
    
  }
  cerr << "2 " << get_time_sec() - et << endl;
  et = get_time_sec();

  const int primeB = 998'244'353;

  {
    Fp::MOD = primeB;
    using TupF = tuple<vector<Fp>, vector<Fp>, vector<Fp>>;
    vector<TupF> tests1({
        {{3,1,0,-2},  {4,3,2,1},        {-5,0,4}},
        {{-1,0,0,0,1},{2,4,6},          {1,-3}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {0}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {3}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {2,1}},
        {{5,1},       {4,0,-1,1},       {4}},
        {{4,3},       {9},              {-2}},
        {{-1,3},      {9},              {0}},
        {{-1,3},      {0},              {3}},
        {{-1,-7},     {0},              {0}},
        {{3},         {4,3,2,1},        {0}}
      });
    for (auto [vq, vd, vm] : tests1) {
      PolyFp q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      DLOGK(p, q, d, m, dd, mm);
      assert(d == dd && m == mm);
      if (q.degree() == 1) {
        auto [ddd, mmm] = p.divideLinear(-q.coef[0] / q.coef[1]);
        DLOGK(p, q, d, m, ddd, mmm);
        assert(ddd == q.coef[1] * d && PolyFp(mmm) == m);
      }
    }

    using TupL = tuple<vector<ll>, vector<ll>, vector<ll>>;
    vector<TupL> tests2({
        {{3,1,0,-2},  {4,3,2,1},        {-5,0,4}},
        {{-1,0,0,0,1},{2,4,6},          {1,-3}},
        {{2,4,6},     {-1,0,0,0,1},     {1,-3}},
        {{5,1},       {4,0,-1,1},       {4}},
        {{4,5},       {9,0,-2},         {3}},
        {{4,1},       {9},              {-2}},
        {{-3,1},      {9},              {0}},
        {{-8,1},      {0},              {3}},
        {{5,1},     {0},              {0}},
      });
    for (auto [vq, vd, vm] : tests2) {
      PolyLL q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      assert(d == dd && m == mm);
      if (q.degree() == 1 && q.coef[1] == 1) {
        auto [ddd, mmm] = p.divideLinear(-q.coef[0]);
        DLOGK(p, q, d, m, ddd, mmm);
        assert(ddd == d && PolyLL(mmm) == m);
      }
    }

    using Pol = Polynomial<double, 0>;
    using Tup = tuple<vector<double>, vector<double>, vector<double>>;
    vector<Tup> tests3({
        {{0,0,0,2},  {-3,4,1},   {1,-3}},
        {{4,3,2,1},   {4,3,2,1}, {1,-3}}
      });
    for (auto [vq, vd, vm] : tests3) {
      Pol q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      assert(d == dd && m == mm);
    }

  }
  cerr << "3 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    Fp::MOD = primeB;
    vector<Fp> v1, v2;
    const int sz = 100;
    for (int i = 0; i < sz + 1; i++) {
      v1.push_back(randrange(0, primeB));
      v2.push_back(randrange(0, primeB));
    }
    v1[sz] = v2[sz] = 1;
    auto pol1X = Polynomial<Fp, 0>(v1);
    auto pol2X = Polynomial<Fp, 0>(v2);
    auto pol1Y = Polynomial<Fp, 1>(v1);
    auto pol2Y = Polynomial<Fp, 1>(v2);
    auto pol3X = pol1X * pol2X;
    auto pol3Y = pol1Y * pol2Y;
    assert(pol3X.degree() == 2 * sz);
    assert(pol3Y.degree() == 2 * sz);
    for (ll i = 0; i <= 2 * sz; i++) {
      assert(pol3X.coef[i] == pol3Y.coef[i]);
    }
  }
  cerr << "4 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    vector<ll> v1, v2;
    const int sz = 100;
    for (int i = 0; i < sz + 1; i++) {
      v1.push_back(randrange(0, 1LL << 30));
      v2.push_back(randrange(0, 1LL << 30));
    }
    v1[sz] = v2[sz] = 1;
    auto pol1X = Polynomial<ll, 0>(v1);
    auto pol2X = Polynomial<ll, 0>(v2);
    auto pol1Y = Polynomial<ll, 2>(v1);
    auto pol2Y = Polynomial<ll, 2>(v2);
    auto pol3X = pol1X * pol2X;
    auto pol3Y = pol1Y * pol2Y;
    assert(pol3X.degree() == 2 * sz);
    assert(pol3Y.degree() == 2 * sz);
    for (ll i = 0; i <= 2 * sz; i++) {
      assert(pol3X.coef[i] == pol3Y.coef[i]);
    }
  }
  cerr << "5 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using Pol = PolyLL;
    Pol X = Pol::get_X();
    Pol p1 = Pol(1), p2 = Pol(1) - X;
    auto a = p1.divFormalSeries(p2, 70);
    for (ll i = 0; i <= 70; i++) {
      assert(a.coef[i] == 1);
      assert(bostanMori(p1, p2, 1) == 1);
    }
  }
  cerr << "6 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    Fp::MOD = primeB;
    using Pol = PolyFp;
    Pol X = Pol::get_X();
    Pol p1 = Pol(1), p2 = Pol(1) - X - X*X;
    assert(bostanMori(p1, p2, 0) == Fp(1));
    assert(bostanMori(p1, p2, 1) == Fp(1));
    assert(bostanMori(p1, p2, 2) == Fp(2));
    assert(bostanMori(p1, p2, 10) == 89);
    auto a = p1.divFormalSeries(p2, 10);
    assert(a.coef == vector<Fp>({1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89}));

    for (ll t = 0; t < 10; t++) {
      ll degP = randrange(0, 100);
      ll degQ = degP + randrange(1, 100);
      ll lim = 10;
      vector<Fp> coefP(degP + 1);
      vector<Fp> coefQ(degQ + 1);
      for (ll i = 0; i < degP + 1; i++) coefP[i] = randrange(-lim, lim + 1);
      for (ll i = 1; i < degQ + 1; i++) coefQ[i] = randrange(-lim, lim + 1);
      coefQ[0] = 1;
      while (coefQ[degQ] == Fp(0)) coefQ[degQ] = randrange(-lim, lim + 1);
      Pol p(coefP), q(coefQ);
      ll degR = 2 * degQ;
      auto r = p.divFormalSeries(q, degR);
      assert(r.coef[degR] == bostanMori(p, q, degR));
      for (ll i = 0; i < 10; i++) {
        ll idx = randrange(0, degR);
        assert(r.coef[idx] == bostanMori(p, q, idx));
      }
    }
  }
  cerr << "7 " << get_time_sec() - et << endl;
  et = get_time_sec();

  cout << "test done." << endl;

  return 0;
}

