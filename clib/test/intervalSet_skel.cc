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
    itv_set<int> isA(0);
    isA.put(2, 1);
    isA.put(3, 1);
    isA.put(4, 1);
    isA.put(10, 1);
    isA.put(13, 1);
    isA.put(14, 1);
    // represents {2,3,4,10,13,14} == [2,5) \cup [10, 11) \cup [13, 15)
    itv_set<int> isB(0);
    isB.put(2, 5, 1);
    isB.put(10, 11, 1);
    isB.put(13, 15, 1);
    itv_set<int> isC(0);
    isC.put_at_end(2, 1);
    isC.put_at_end(5, 0);
    isC.put_at_end(10, 1);
    isC.put_at_end(11, 0);
    isC.put_at_end(13, 1);
    isC.put_at_end(15, 0);
    for (ll i = -10; i < 20; i++) assert(isA.get(i) == isB.get(i));
    for (ll i = -10; i < 20; i++) assert(isA.get(i) == isC.get(i));
    assert(isA.impl == isB.impl);
    assert(isA.impl == isC.impl);
    {
      auto it = isA.get_iter(3);
      assert(it->first == 2 and it->second == 1);
    }
    {
      auto it = isA.get_iter(8);
      assert(it->first == 5 and it->second == 0 and next(it)->first == 10);
    }
  }
  {
    itv_set<string> is1;
    is1.put(-40, -20, "hello");
    assert(is1.get_val(100) == "");
    assert(is1.get_val(-40) == "hello");
    assert(is1.get_val(-20) == "");
    itv_set<string> is2("world");
    is2.put(90, "globe");
    assert(is2.get_val(50) == "world");
    assert(is2.get_val(89) == "world");
    assert(is2.get_val(90) == "globe");
    assert(is2.get_val(91) == "world");
    auto [l, r] = is2.get_itvl(90);
    assert(l == 90 and r == 91);
    auto [l2, r2] = is2.get_itvl(91);
    assert(l2 == 91 and r2 == LLONG_MAX);
  }
  {
    ll nc = 1000;
    ll sz = 40;
    ll mutL = 10;
    ll mutR = 20;
    ll vmax = sz * 2;
    for (ll i = 0; i < nc; i++) {
      vector<ll> vec(sz);
      itv_set<ll> is;
      for (ll j = 0; j < sz; j++) {
        vec[j] = randrange(0, vmax);
        is.put_at_end(j, vec[j]);
      }
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
      for (ll j = 0; j < sz; j++) assert(vec[j] == is.get_val(j));
      for (ll j = 0; j < sz; j++) {
        auto [v, iv] = is.get(j);
        auto [l, r] = iv;
        assert(l <= j and j < r and vec[j] == v);
        assert(iv == is.get_itvl(j));
      }
      for (auto it = is.impl.begin(); std::next(it)->first < LLONG_MAX; it++) {
        assert(it->second != std::next(it)->second);
      }
    }
  }
  {
    ll nc = 1000;
    ll sz = 40;
    ll mutL = 10;
    ll mutR = 20;
    for (ll i = 0; i < nc; i++) {
      vector<bool> vecA(sz), vecB(sz);
      itv_set<bool> isA, isB;
      for (ll j = 0; j < sz; j++) {
        vecA[j] = randrange(0, 2) == 0 ? false : true;
        isA.put_at_end(j, vecA[j]);
        vecB[j] = randrange(0, 2) == 0 ? false : true;
        isB.put_at_end(j, vecB[j]);
      }
      ll mut = randrange(mutL, mutR);
      for (ll k = 0; k < mut; k++) {
        ll l = randrange(0, sz - 1);
        ll r = randrange(l + 1, sz);
        ll x = randrange(0, 2) == 0 ? false : true;
        if (k % 3 == 0) {
          isA.put(l, r, x);
          for (ll j = l; j < r; j++) vecA[j] = x;
        }else if (k % 3 == 1) {
          isB.put(l, r, x);
          for (ll j = l; j < r; j++) vecB[j] = x;
        }else {
          isA = itv_apply([](bool p, bool q) -> bool { return p ^ q; }, isA, isB);
          for (ll j = 0; j < sz; j++) vecA[j] = vecA[j] ^ vecB[j];
        }
      }
      for (ll j = 0; j < sz; j++) assert(vecA[j] == isA.get_val(j) and vecB[j] == isB.get_val(j));
      for (ll j = 0; j < sz; j++) {
        auto [v, iv] = isA.get(j);
        auto [l, r] = iv;
        assert(l <= j and j < r and vecA[j] == v);
        assert(iv == isA.get_itvl(j));
      }
      for (ll j = 0; j < sz; j++) {
        auto [v, iv] = isB.get(j);
        auto [l, r] = iv;
        assert(l <= j and j < r and vecB[j] == v);
        assert(iv == isB.get_itvl(j));
      }
      for (auto it = isA.impl.begin(); std::next(it)->first < LLONG_MAX; it++) {
        assert(it->second != std::next(it)->second);
      }
      for (auto it = isB.impl.begin(); std::next(it)->first < LLONG_MAX; it++) {
        assert(it->second != std::next(it)->second);
      }
    }
  }

  {
    itv_set<int> isA(0);
    isA.put_at_end(30, 5000);
    isA.put_at_end(60, 6000);
    itv_set<int> isB(0);
    isB.put_at_end(40, 300);
    isB.put_at_end(60, 200);
    isB.put_at_end(80, 100);
    auto op = [&](int& x, int y) -> int { return x + y; };
    auto isC = itv_apply(op, isA, isB);
    itv_set<int> isD(0);
    isD.put_at_end(30, 5000);
    isD.put_at_end(40, 5300);
    isD.put_at_end(60, 6200);
    isD.put_at_end(80, 6100);
    assert(isC.impl == isD.impl);
  }

  cout << "ok\n";
}
