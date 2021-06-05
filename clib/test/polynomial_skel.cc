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
    assert(p1.getCoef(0) == -2 && p1.getCoef(1) == 0 && p1.getCoef(2) == 1);

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

    const auto& X = SparsePoly<ll>::X;
    assert((X - 1LL) * (X - 1LL) == (X * X) - 2LL * X + 1LL);

    using Fp = FpG<2>;
    auto Y = Polynomial<Fp, 0>({0,1});
    assert((Y - Fp(1)) * (Y - Fp(1)) == (Y * Y) + Fp(1));

    PolyLL pzero;
    assert(2 * p5 != p5);
    assert(p5 + pzero == p5);
    assert(p5 - pzero == p5);
    assert(p5 * pzero == pzero);
    assert(pzero + p5 == p5);
    assert(pzero - p5 == -p5);
    assert(pzero * p5 == pzero);
    DLOGK(p5 - p5);
    DLOGK(pzero);
    assert(p5 - p5 == pzero);
    assert(p5 * 0 == pzero);
    assert(p5 + 0 == p5);
    assert(0 * p5 == pzero);
    assert(0 + p5 == p5);

  }
  {
    SparsePoly<ll> X = SparsePoly<ll>::X;

    vector<ll> vec1({1, 0, 2});
    SparsePoly<ll> sp1(vec1);
    SparsePoly<ll> sp1a({{0,1}, {2,2}});
    // DLOGK(sp1, sp1a);
    assert(sp1 == sp1a);
    Polynomial<ll, 0> pol1(vec1);
    SparsePoly<ll> sp2(pol1);
    assert(sp1 == sp2);
    sp1 = vector<ll>({4, 1});
    assert(sp1 == SparsePoly<ll>({{0,4}, {1,1}}));
    sp1 = {{5, 2}};
    assert(sp1 == 2*X*X*X*X*X);
    sp1 = vector<pair<ll, ll>>({{2, -3}});
    assert(sp1 == -3*X*X);
  }

  cerr << "1 " << get_time_sec() - et << endl;
  et = get_time_sec();
  {
    using Fp = FpA;
    using Pol = Polynomial<Fp, 0>;
    Pol p1;
    assert(p1.degree() == -1);
    Pol p2(Fp(10));
    assert(p2.degree() == 0 && p2.getCoef(0) == Fp(10));
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

  {
    using Fp = FpB;
    using TupF = tuple<vector<Fp>, vector<Fp>, vector<Fp>>;
    vector<TupF> tests1({
        {{3,1,0,-2},  {4,3,2,1},        {-5,0,4}},
        {{-1,0,0,0,1},{2,4,6},          {1,-3}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {3}},
        {{-3,4,1},    {7,6,5,4,3,2,1},  {2,1}},
        {{5,1},       {4,0,-1,1},       {4}},
        {{4,3},       {9},              {-2}},
        {{-1,3},      {9},              {}},
        {{-1,3},      {},               {3}},
        {{-1,-7},     {},               {}},
        {{3},         {4,3,2,1},        {}}
      });
    for (auto [vq, vd, vm] : tests1) {
      PolyFpB q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      DLOGK(p, q, d, m, dd, mm);
      assert(d == dd && m == mm);
      if (q.degree() == 1) {
        auto [ddd, mmm] = p.divideLinear(-q.getCoef(0) / q.getCoef(1));
        DLOGK(p, q, d, m, ddd, mmm);
        assert(ddd == q.getCoef(1) * d && PolyFpB(mmm) == m);
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
        {{-3,1},      {9},              {}},
        {{-8,1},      {},               {3}},
        {{5,1},       {},               {}},
      });
    for (auto [vq, vd, vm] : tests2) {
      PolyLL q(vq), d(vd), m(vm);
      auto p = q * d + m;
      auto [dd, mm] = p.divmod(q);
      assert(d == dd && m == mm);
      if (q.degree() == 1 && q.getCoef(1) == 1) {
        auto [ddd, mmm] = p.divideLinear(-q.getCoef(0));
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
    using Fp = FpB;
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
      assert(pol3X.getCoef(i) == pol3Y.getCoef(i));
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
      assert(pol3X.getCoef(i) == pol3Y.getCoef(i));
    }
  }
  cerr << "5 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using Pol = PolyLL;
    const auto& X = SparsePoly<ll>::X;
    Pol p1 = Pol(1), p2 = Pol(1) - X;
    auto a = p1.divFormalSeries(p2, 70);
    for (ll i = 0; i <= 70; i++) {
      assert(a.getCoef(i) == 1);
      assert(bostanMori(p1, p2, 1) == 1);
    }
  }
  cerr << "6 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using Fp = FpB;
    using Pol = PolyFpB;
    const auto& X = Pol::X;
    Pol p1 = Pol(1), p2 = Pol(1) - X - X*X;
    assert(bostanMori(p1, p2, 0) == Fp(1));
    assert(bostanMori(p1, p2, 1) == Fp(1));
    assert(bostanMori(p1, p2, 2) == Fp(2));
    assert(bostanMori(p1, p2, 10) == 89);
    auto a = p1.divFormalSeries(p2, 10);
    assert(a.coefVec() == vector<Fp>({1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89}));

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
      assert(r.getCoef(degR) == bostanMori(p, q, degR));
      for (ll i = 0; i < 10; i++) {
        ll idx = randrange(0, degR);
        assert(r.getCoef(idx) == bostanMori(p, q, idx));
      }
    }
  }
  cerr << "7 " << get_time_sec() - et << endl;
  et = get_time_sec();

  {
    using SP = SparsePoly<ll>;
    SP sp1;
    SP sp2({{0, 1}, {1, -3}, {2, 3}, {3, -1}});
    SP sp3({{1, 1}});
    SP sp4 = SP::X;
    SP sp52 = SP::Xn(2);
    SP sp53 = SP::Xn(3);
    SP sp6 = 1LL - sp4;
    SP sp7 = sp6 * sp6 * sp6;
    SP sp8 = 1LL - 3 * sp4 + 3 * sp52 - sp53;
    assert(sp8 * 0 == sp1);
    assert(sp8 - sp8 == sp1);
    assert(sp2 == sp8);
    assert(sp2 == sp7);

    assert(PolyLL({1,2}) - SP::Xn(5) == PolyLL({1,2,0,0,0,-1}));
    assert(PolyLL({10,11,12}) - 12 * SP::Xn(2) == PolyLL({10,11}));
    assert(PolyLL() * SP() == PolyLL());
    assert(SP() * PolyLL() == PolyLL());
    assert(PolyLL() * SP::Xn(2) == PolyLL());
    assert(SP::Xn(2) * PolyLL() == PolyLL());
  }
  {
    using SP = SparsePoly<ll>;
    PolyLL p1({1, 2, 3});
    SP sp1 = 4LL - SP::Xn(2);
    assert(p1 + sp1 == PolyLL({5, 2, 2}));
    assert(p1 - sp1 == PolyLL({-3, 2, 4}));
    assert(p1 * sp1 == PolyLL({4, 8, 11, -2, -3}));
    PolyLL p2({1, 2, 3, 4, 5});
    p2 = sp1;
    assert(p2 == PolyLL(sp1));
    p2 = 0;
    assert(p2 == PolyLL());
    PolyLL p4({1, 2, 3, 0, 5});
    assert(p4.cutoff(2) == PolyLL({1, 2, 3}));
    assert(p4.cutoff(3) == PolyLL({1, 2, 3}));
    assert(p4.cutoff(10) == p4);
    assert(p4.cutoff(0) == 1);
    assert(p4.cutoff(-1) == 0);
    PolyLL p5;
    p5 = p4; p5.selfCutoff(2); assert(p5 == PolyLL({1, 2, 3}));
    p5 = p4; p5.selfCutoff(3); assert(p5 == PolyLL({1, 2, 3}));
    p5 = p4; p5.selfCutoff(10); assert(p5 == p4);
    p5 = p4; p5.selfCutoff(0); assert(p5 == 1);
    p5 = p4; p5.selfCutoff(-1); assert(p5 == 0);

    PolyLL p10({1,2,3,4,5,6,7});
    SP sp10({{0,1}, {2,-1}, {4,2}});
    assert(p10.mult(sp10, 0) == (p10 * sp10).cutoff(0));
    assert(p10.mult(sp10, 2) == (p10 * sp10).cutoff(2));
    assert(p10.mult(sp10, 10) == (p10 * sp10).cutoff(10));
    assert(p10.mult(sp10, 15) == (p10 * sp10).cutoff(15));
  }

  {
    using SP = SparsePoly<ll>;
    ll rep = 1000;
    for (ll z = 0; z < rep; z++) {
      ll deg1 = randrange(0, 10);
      vector<ll> v1(deg1 + 1);
      for (ll i = 0; i <= deg1; i++) v1[i] = randrange(-20, 20);
      PolyLL p1(v1);
      ll size2 = randrange(0, 5);
      vector<pair<ll, ll>> v2;
      ll cur = -1;
      for (ll i = 0; i < size2; i++) {
        cur += randrange(1, 4);
        v2.emplace_back(cur, randrange(-20, 20));
      }
      SP sp2(v2);
      PolyLL p3 = p1.mult(sp2);
      PolyLL p4 = p1 * PolyLL(sp2);
      assert(p3 == p4);
      PolyLL p5 = p1.mult(sp2, deg1);
      assert (p5 == p4.cutoff(deg1));

      ll y = randrange(0,2) == 0 ? 1LL : -1LL;
      SP sp3 = sp2 - PolyLL(sp2).getCoef(0) + y;
      
      PolyLL p6 = p1.divFPS(sp3);
      PolyLL p7 = (p6 * sp3 - p1).cutoff(p1.degree());
      assert(p7 == 0);
      PolyLL p8 = p1.divFPS(sp3, 4);
      PolyLL p9 = (p8 * sp3 - p1).cutoff(min(4, sp3.degree()));
      assert(p9 == 0);
    }
  }



  cout << "test done." << endl;

  return 0;
}

