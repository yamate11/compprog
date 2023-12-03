#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
using pll = pair<ll, ll>;

// @@ !! LIM(intervalSet debug)

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
    itv_set<int> isA(-10, 20, 0);
    isA.put(2, 1);
    isA.put(3, 1);
    isA.put(4, 1);
    isA.put(10, 1);
    isA.put(13, 1);
    isA.put(14, 1);
    // represents {2,3,4,10,13,14} == [2,5) \cup [10, 11) \cup [13, 15)
    itv_set<int> isB(-10, 20, 0);
    isB.put(2, 5, 1);
    isB.put(10, 11, 1);
    isB.put(13, 15, 1);
    for (ll i = -10; i < 20; i++) assert(isA.get(i) == isB.get(i));
    assert(isA.impl == isB.impl);
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
    itv_set<string> is1(LLONG_MIN, LLONG_MAX);
    is1.put(-40, -20, "hello");
    assert(is1.get_val(100) == "");
    assert(is1.get_val(-40) == "hello");
    assert(is1.get_val(-20) == "");
    itv_set<string> is2(LLONG_MIN, LLONG_MAX, "world");
    is2.put(90, "globe");
    assert(is2.get_val(50) == "world");
    assert(is2.get_val(89) == "world");
    assert(is2.get_val(90) == "globe");
    assert(is2.get_val(91) == "world");
    auto [l, r, _dummy1] = is2.get(90);
    assert(l == 90 and r == 91);
    auto [l2, r2, _dummy2] = is2.get(91);
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
      itv_set<ll> is(0, sz);
      for (ll j = 0; j < sz; j++) {
        vec[j] = randrange(0, vmax);
        is.put(j, vec[j]);
      }
      ll mut = randrange(mutL, mutR);
      for (ll k = 0; k < mut; k++) {
        ll l = randrange(0, sz);
        ll r = randrange(l + 1, sz + 1);
        ll x = randrange(0, vmax);
        if (k % 2 == 0) {
          is.put(l, r, x);
          for (ll j = l; j < r; j++) vec[j] = x;
        }else {
          is.put(l, x);
          vec[l] = x;
        }
      }
      for (ll j = 0; j < sz; j++) {
        auto [l, r, v] = is.get(j);
        assert(l <= j and j < r and vec[j] == v and vec[j] == is.get_val(j));
      }
      for (auto it = is.impl.begin(); std::next(it)->first < sz; it++) {
        assert(it->second != std::next(it)->second);
      }
      ll prev_r = 0;
      ll prev_t = LLONG_MIN;
      for (const auto& [l, r, t] : is) {
        assert(l == prev_r);
        assert(t != prev_t);
        assert(l < r);
        for (ll k = l; k < r; k++) assert(vec[k] == t);
        prev_r = r;
        prev_t = t;
      }
      assert(prev_r == sz);
    }
  }
  {
    ll nc = 1000;
    ll sz = 40;
    ll mutL = 10;
    ll mutR = 20;
    for (ll i = 0; i < nc; i++) {
      vector<bool> vecA(sz), vecB(sz);
      itv_set<bool> isA(0, sz), isB(0, sz);
      for (ll j = 0; j < sz; j++) {
        vecA[j] = randrange(0, 2) == 0 ? false : true;
        isA.put(j, vecA[j]);
        vecB[j] = randrange(0, 2) == 0 ? false : true;
        isB.put(j, vecB[j]);
      }
      ll mut = randrange(mutL, mutR);
      for (ll k = 0; k < mut; k++) {
        ll l = randrange(0, sz);
        ll r = randrange(l + 1, sz + 1);
        ll x = randrange(0, 2) == 0 ? false : true;
        if (k % 3 == 0) {
          isA.put(l, r, x);
          for (ll j = l; j < r; j++) vecA[j] = x;
        }else if (k % 3 == 1) {
          isB.put(l, r, x);
          for (ll j = l; j < r; j++) vecB[j] = x;
        }else {
          auto ff = [](bool p, bool q) -> bool { return p ^ q; };
          isA = itv_apply(ff, isA, isB);
          for (ll j = 0; j < sz; j++) vecA[j] = vecA[j] ^ vecB[j];
        }
      }
      for (ll j = 0; j < sz; j++) assert(vecA[j] == isA.get_val(j) and vecB[j] == isB.get_val(j));
      for (ll j = 0; j < sz; j++) {
        auto [l, r, v] = isA.get(j);
        assert(l <= j and j < r and vecA[j] == v);
      }
      for (ll j = 0; j < sz; j++) {
        auto [l, r, v] = isB.get(j);
        assert(l <= j and j < r and vecB[j] == v);
      }
      for (auto it = isA.impl.begin(); std::next(it)->first < sz; it++) {
        assert(it->second != std::next(it)->second);
      }
      for (auto it = isB.impl.begin(); std::next(it)->first < sz; it++) {
        assert(it->second != std::next(it)->second);
      }
    }
  }
  {
    itv_set<int> isA(0, 100, 0);
    isA.put(30, 60, 5000);
    isA.put(60, 100, 6000);
    itv_set<int> isB(0, 100, 0);
    isB.put(40, 60, 300);
    isB.put(60, 80, 200);
    isB.put(80, 100, 100);
    auto op = [&](int x, int y) -> int { return x + y; };
    auto isC = itv_apply(op, isA, isB);
    itv_set<int> isD(0, 100, 0);
    isD.put(30, 40, 5000);
    isD.put(40, 60, 5300);
    isD.put(60, 80, 6200);
    isD.put(80, 100, 6100);
    assert(isC.impl == isD.impl);
  }

  {
    itv_set<pll> isA(0, 100);
    itv_set<pll> isB(0, 100);
    isA.put(10, 20, pll{3, 4});
    isA.put(20, 30, pll{5, 6});
    isB.put(5, 15, pll{10, 20});
    isB.put(15, 25, pll{30, 40});
    auto myadd = [&](pll p1, pll p2) -> pll { return pll{p1.first + p2.first, p1.second + p2.second}; };
    auto isC = itv_apply(myadd, isA, isB);
    auto [l, r, t1] = isC.get(12);
    assert(t1 == pll(13, 24) and l == 10 and r == 15);
    assert(isC.get_val(17) == pll(33, 44));
    assert(isC.get(22) == make_tuple(20, 25, pll(35, 46)));
  }
  {
    itv_set<int> is(0, 100, 10);
    is.put(15, 20, 2);
    is.put(25, 30, 1);
    assert(is.sum(10, 15) == 50);
    assert(is.sum(15, 20) == 10);
    assert(is.sum(14, 16) == 12);
    assert(is.sum(12, 32) == 3 * 10 + 5 * 2 + 5 * 10 + 5 * 1 + 2 * 10);
    is.put(27, 27, 1000);
    is.put(27, 25, 2000);
    assert(is.get_val(27) == 1);
    auto [l0, r0, t0] = is.get(27);
    assert(l0 == 25 and r0 == 30);
  }
  {
    vector<itv_set<int>> vis(4);
    vis[0].put(0, 10, 10);
    vis[1].put(5, 20, 20);
    vis[2].put(0, 5, 10);
    vis[2].put(5, 10, 30);
    vis[2].put(10, 20, 20);
    vis[3] = itv_apply(plus<int>(), vis[0], vis[1]);
    assert(vis[0] != vis[1]);
    assert(vis[2] == vis[3]);
  }

  cout << "ok\n";
}
