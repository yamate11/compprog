#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< f:perfmeas sieve)

int main() {

  {
    auto p = sieve(1000);
    assert(p.at(10) == 31);
    assert(p.at(100) == 547);
    auto p1 = sieve(547);
    assert(p1.at(100) == 547);
    auto t = prfac(4*5*49);
    assert(t.at(0).first == 2 && t.at(0).second == 2 &&
	   t.at(1).first == 5 && t.at(1).second == 1 &&
	   t.at(2).first == 7 && t.at(2).second == 2 &&
	   t.size() == 3);
    auto ds = getDivisors(4*5*49);
    sort(ds.begin(), ds.end());
    assert(ds.size() == 18 && ds.at(0) == 1 && ds.at(1) == 2 && ds.at(2) == 4
	   && ds.at(3) == 5 && ds.at(4) == 7 && ds.at(15) == 245 &&
	   ds.at(16) == 490 && ds.at(17) == 980);
    auto t2 = prfac(258141461878361);
    assert(t2.at(0).first ==  97 && t2.at(0).second == 2 &&
	   t2.at(1).first == 401 && t2.at(1).second == 1 &&
	   t2.at(2).first == 409 && t2.at(2).second == 3 &&
	   t2.size() == 3);
    auto ds2 = getDivisors(990728680597);
    sort(ds2.begin(), ds2.end());
    vector<ll> ds2A = {1, 9967, 9973, 9967*9967, 9967*9973, 9967LL*9967*9973};
    assert(ds2.size() == ds2A.size());
    for (size_t i = 0; i < ds2.size(); i++) assert(ds2.at(i) == ds2A.at(i));
  }

  {
    auto divSieve = divisorSieve(100000);
    vector<pair<int, int>> vec1({{3,1}, {7,2}});
    assert(prfacDivSieve(3*7*7, divSieve) == vec1);
    vector<pair<int, int>> vec2({{283,1}, {293,1}});
    // cout << prfacDivSieve(283*293, divSieve);
    assert(prfacDivSieve(283*293, divSieve) == vec2);
    assert(divSieve[283*293] == 283);
    assert(divSieve[5*1511] == 5);
    assert(divSieve[99991] == 99991);
  }

  {
    ll n = 1e5;
    auto primes = sieve(sqrt(n) + 1);
    auto divSieve = divisorSieve(n);
    for (ll i = 2; i <= n; i++) {
      auto pr1 = prfac(i, primes);
      auto pr2 = prfacDivSieve(i, divSieve);
      assert(pr1.size() == pr2.size());
      for (ll j = 0; j < (ll) pr1.size(); j++) {
	auto [p1, r1] = pr1[j];
	auto [p2, r2] = pr2[j];
	assert(p1 == p2 && r1 == r2);
      }
    }
  }
  {
    // performance
    ll n = 1e6;
    double t1 = get_time_sec();
    ll dummy = 0;
    auto primes = sieve(n);
    for (ll i = 2*n/3; i < n; i++) {
      auto pr = prfac(i, primes);
      dummy += pr.size();
    }
    double t2 = get_time_sec();
    auto divSieve = divisorSieve(n);
    for (ll i = 2*n/3; i < n; i++) {
      auto pr = prfacDivSieve(n, divSieve);
      dummy += pr.size();
    }
    double t3 = get_time_sec();
    cout << t2 - t1 << ", " << t3 - t2 << endl;
    cout << primes[0] << divSieve[0] << dummy << endl;
  }
  {
    ll n = 1e7;
    double t1 = get_time_sec();
    auto primes = sieve(ll(sqrt(n)) + 1);
    auto pr1 = prfac(n, primes);
    double t2 = get_time_sec();
    auto divSieve = divisorSieve(n);
    auto pr2 = prfacDivSieve(n, divSieve);
    double t3 = get_time_sec();
    cout << t2 - t1 << ", " << t3 - t2 << endl;
    assert(pr1.size() == pr2.size());
  }

  cerr << "OK\n";
}
