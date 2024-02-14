#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug f:<< f:>> f:gcd f:updMaxMin f:intDiv f:mex f:shortVector f:perfmeas f:itrange)


int main() {

  random_device rd;
  mt19937 rng(rd());

  assert(divFloor( 18,  3) ==  6);
  assert(divCeil(  18,  3) ==  6);
  assert(divFloor(-18,  3) == -6);
  assert(divCeil( -18,  3) == -6);
  assert(divFloor( 18, -3) == -6);
  assert(divCeil(  18, -3) == -6);
  assert(divFloor(-18, -3) ==  6);
  assert(divCeil( -18, -3) ==  6);

  assert(divFloor( 19,  3) ==  6);
  assert(divCeil(  19,  3) ==  7);
  assert(divFloor(-19,  3) == -7);
  assert(divCeil( -19,  3) == -6);
  assert(divFloor( 19, -3) == -7);
  assert(divCeil(  19, -3) == -6);
  assert(divFloor(-19, -3) ==  6);
  assert(divCeil( -19, -3) ==  7);

  assert(divFloor( 20,  3) ==  6);
  assert(divCeil(  20,  3) ==  7);
  assert(divFloor(-20,  3) == -7);
  assert(divCeil( -20,  3) == -6);
  assert(divFloor( 20, -3) == -7);
  assert(divCeil(  20, -3) == -6);
  assert(divFloor(-20, -3) ==  6);
  assert(divCeil( -20, -3) ==  7);

  {
    assert(imod( 3,  7) ==  3);
    assert(imod(-3,  7) ==  4);
    assert(imod( 3, -7) == -4);
    assert(imod(-3, -7) == -3);
    assert(imod( 100,  7) ==  2);
    assert(imod(-100,  7) ==  5);
    assert(imod( 100, -7) == -5);
    assert(imod(-100, -7) == -2);
    assert(imod(0, 5) == 0);
    assert(imod(0, -5) == 0);
    assert(imod( 9, 1) == 0);
    assert(imod( 9, -1) == 0);
    assert(imod(-9, 1) == 0);
    assert(imod(-9, -1) == 0);
    assert(imod( 22,  11) == 0);
    assert(imod( 22, -11) == 0);
    assert(imod(-22,  11) == 0);
    assert(imod(-22, -11) == 0);
  }

  {
    vector<pair<ll, ll>> v({
	{5,8},{540,150},{-70,105},{14,-30},{-33,24},{-35,-99}
        ,{-70,105},{105,-70},{70,-105},{-105,70},{70,105},{105,70},{-70,-105},{-105,-70}
	,{0,6},{6,0},{0,-6},{-6,0},{0,0}});
    for (auto [a, b] : v) {
      auto [g, s, t] = eGCD(a, b);
      // DLOGK(g, gcd(a, b), a, b, s, t, a*s + b*t);
      assert(g == gcd(a, b) && a * s + b * t == g);
    }
  }
  {
    for (ll x1 = 1; x1 <= 12; x1++) {
      for (ll x2 = 1; x2 <= 12; x2++) {
	vector rr(x1, vector(x2, -1));
	ll lcm = x1 * x2 / gcd(x1, x2);
	for (ll r = 0; r < lcm; r++) rr[r % x1][r % x2] = r;
	for (ll a1 = 0; a1 < x1; a1++) {
	  for (ll a2 = 0; a2 < x2; a2++) {
	    for (ll c1 = -2; c1 <= 2; c1++) {
	      for (ll c2 = -2; c2 <= 2; c2++) {
		ll aa1 = a1 + c1 * x1;
		ll aa2 = a2 + c2 * x2;

		assert(crt(aa1, x1, aa2, x2) == rr[a1][a2]);
	      }
	    }
	  }
	}
      }
    }
    
    vector<ll> rcs({0,1,53,37193,409287402,32123784915});
    vector<ll> xs({  2,4,  8,  3,5, 6,15,24,30});
    for (ll rc : rcs) {
      vector<ll> as;
      for (ll x : xs) as.push_back(rc % x);
      ll r = crt(as, xs);
      // DLOGK(as, xs);
      assert(r >= 0);
      for (ll i = 0; i < (ll)as.size(); i++) {
	assert((r - as[i]) % xs[i] == 0);
      }
    }
    vector<ll> as1({1,1,1,1,1,4,1,1,1});
    assert(crt(as1, xs) == -1);
  }

  {
    uniform_int_distribution<ll> dist9(1, (ll)1e9);
    uniform_int_distribution<ll> dist9z(-(ll)1e9, (ll)1e9);
    uniform_int_distribution<ll> dist18(1, (ll)1e18);
    for (ll i = 0; i < 1000; i++) {
      ll r0 = dist18(rng);
      ll x1 = dist9(rng);
      ll x2 = dist9(rng);
      ll a1 = r0 % x1;
      ll a2 = r0 % x2;
      a1 += dist9z(rng) * x1;
      a2 += dist9z(rng) * x2;
      ll r = crt(a1, x1, a2, x2);
      bool b = r >= 0 && (r - a1) % x1 == 0 && (r - a2) % x2 == 0;
      if (!b) {
	DLOGK(r, a1, x1, a2, x2);
	assert(false);
      }
    }
  }


  {
    set<ll> s1({5, 2, 4});
    set<ll, greater<ll>> s2({5, 2, 4});
    stringstream ss;
    ss << s1 << " " << s2;
    assert(ss.str() == "{2, 4, 5} {5, 4, 2}");
  }

  {
    vector<ll> v1(3000);
    iota(v1.begin(), v1.end(), 0);
    assert(mex(v1.begin(), v1.end()) == 3000);
    v1[2500] = 500;
    assert(mex(v1.begin(), v1.end()) == 2500);
    v1[100] = 500;
    assert(mex(v1.begin(), v1.end()) == 100);
    v1[0] = 500;
    assert(mex(v1.begin(), v1.end()) == 0);
  }

  {
    ll sv = 0;
    for (ll i = 0; i < 9; i++) sv_set(2, sv, i, i % 4);
    assert(sv_show(2, sv, 9) == "[0, 1, 2, 3, 0, 1, 2, 3, 0]");
    assert(sv_show(2, sv) == "[0, 1, 2, 3, 0, 1, 2, 3]");
    for (ll i = 0; i < 6; i++) {
      sv_set(2, sv, i, (sv_get(2, sv, i) + 1) % 4);
    }
    assert(sv_show(2, sv, 9) == "[1, 2, 3, 0, 1, 2, 2, 3, 0]");
  }

  {
    stringstream ss1("5 2 4 -1");
    pair<int, int> p1, p2, q1({5, 2}), q2({4, -1});
    ss1 >> p1 >> p2;
    assert(p1 == q1 && p2 == q2);

    stringstream ss2("4 0 5 2 abc 1 -9");
    tuple<int, int, int> t31, ta31({4, 0, 5});
    tuple<int, string, bool, int> t41, ta41({2, "abc", true, -9});
    ss2 >> t31 >> t41;
    assert(t31 == ta31 && t41 == ta41);

    stringstream ss3("5 7 1 2 4 9");
    vector<pair<int, int>> v1(3), va1({{5, 7}, {1, 2}, {4, 9}});
    ss3 >> v1;
    assert(v1 == va1);
    stringstream ss4("5 7 1 2 4 9");
    auto v2 = read_vector_n<pair<int, int>>(ss4, 3);
    assert(v2 == va1);
    stringstream ss5("3 5 7 1 2 4 9");
    auto v3 = read_vector<pair<int, int>>(ss5);
    assert(v3 == va1);
    
  }

  {
    ItRange ir(0, 10);
    vector<ll> vec, w;
    for (ll x : ir) vec.push_back(x);
    for (ll i = 0; i < 10; i++) w.push_back(i);
    assert(vec == w);
    vector<ll> vec2;
    bool b1 = all_of(ir.begin(), ir.end(),
                     [&](ll i) -> bool { return i * i < 10000; });
    bool b2 = all_of(ir.begin(), ir.end(),
                     [&](ll i) -> bool { return i * i < 50; });
    bool b3 = any_of(ir.begin(), ir.end(),
                     [&](ll i) -> bool { return i * i > 80; });
    assert(b1 && !b2 && b3);
    auto it = find_if(ALLIR(0, 10),
                      [&](ll i) -> bool { return i * i > 50; });
    assert (*it == 8);
  }


  cout << "Test done." << endl;
  return 0;
}
