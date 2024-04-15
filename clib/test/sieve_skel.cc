#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< sieve)

int main() {

  {
    using RT = vector<pair<ll, int>>;
    auto s = sieve(97);
    assert(s[s.size() - 1] == 97);
    assert(prfac(2) == RT({{2, 1}}));
    assert(prfac(12) == RT({{2, 2}, {3, 1}}));
    assert(prfac(97*97, sieve(97)) == RT({{97, 2}}));
    assert(prfac(1'000'000'007) == RT({{1'000'000'007, 1}}));
    assert(prfac(1) == RT());
  }

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

  cerr << "OK\n";
}
