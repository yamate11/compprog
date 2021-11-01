#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(intervalSet)

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

  {
    //               0 1 2 3 4 5 6 7 8 91011121314
    vector<int> vec({0,0,1,1,1,0,0,0,0,0,1,0,0,1,1});
    itv_set<int> isA(0, vec);
    // represents {2,3,4,10,13,14} == [2,5) \cup [10, 11) \cup [13, 15)
    itv_set isB(0, 15, 0);
    isB.put(2, 5, 1);
    isB.put(10, 11, 1);
    isB.put(13, 15, 1);
    for (ll i = 0; i < 15; i++) assert(isA.get(i) == isB.get(i));
  }
  {
    ll nc = 1000;
    ll sz = 40;
    ll mutL = 10;
    ll mutR = 20;
    ll vmax = sz * 2;
    for (ll i = 0; i < nc; i++) {
      vector<ll> vec(sz);
      for (ll j = 0; j < sz; j++) vec[j] = randrange(0, vmax);
      itv_set is(0, vec);
      ll mut = randrange(mutL, mutR);
      for (ll k = 0; k < mut; k++) {
        ll l = randrange(0, sz - 1);
        ll r = randrange(l + 1, sz);
        ll x = randrange(0, vmax);
        if (k % 2 == 0) {
          is.put(l, r, x);
          for (ll j = l; j < r; j++) vec[j] = x;
        }else {
          is.put(l, x);
          vec[l] = x;
        }
      }
      for (ll j = 0; j < sz; j++) assert(vec[j] == is.get(j));
      for (ll j = 0; j < sz; j++) {
        auto [l, r, y] = is.get_itv(j);
        assert(l <= j && j < r && is.get(j) == y);
      }
      ll l = randrange(0, sz - 1);
      ll r = randrange(l + 1, sz);
      auto vv = is.get(l, r);
      ll l2 = -1, r2 = -1;
      assert(get<0>(vv[0]) == l);
      assert(get<1>(vv[vv.size() - 1]) == r);
      for (ll p = 0; p < (ll)vv.size() - 1; p++) {
        auto [l1, r1, y1] = vv[p];
        if (l2 >= 0) assert(l2 < l1 && r2 == l1);
        for (ll x = l1; x < r1; x++) assert(is.get(x) == y1);
      }
    }
  }


  cout << "ok\n";
}

  
