#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(intervalSet)

// ---- inserted library file intervalSet.cc

template<typename T>
struct itv_set {
  
  auto get_it(ll x) {
    auto it = repl.lower_bound(x);
    if (it == repl.end()) {
      throw runtime_error("get_it: out of range");
    }
    if (it->first == x) return it;
    if (it == repl.begin()) {
      throw runtime_error("get_it: out of range");
    }
    return prev(it);
  }

  auto get_it(ll x) const {
    auto it = repl.lower_bound(x);
    if (it == repl.end()) {
      throw runtime_error("get_it: out of range");
    }
    if (it->first == x) return it;
    if (it == repl.begin()) {
      throw runtime_error("get_it: out of range");
    }
    return prev(it);
  }

  auto divide(ll x) {
    auto it = get_it(x);
    if (it->first == x) return it;
    auto [y, t] = *it;
    auto [it2, rc] = repl.emplace(x, t);
    assert(rc);
    return it2;
  }

  ll l0;
  ll r0;
  map<ll, T> repl;

  itv_set(ll l0_, ll r0_, T t) : l0(l0_), r0(r0_) {
    repl[l0] = t; repl[r0] = t;
  }
  itv_set(ll l0_, const vector<T>& vec) : l0(l0_), r0(l0_ + (ll)vec.size()) {
    for (int i = 0; i < (int)vec.size(); i++) {
      repl[l0 + i] = vec[i];
    }
    repl[r0] = vec[0];
  }

  void put(ll x, T t) {
    divide(x + 1);
    auto it = divide(x);
    it->second = t;
  }

  void put(ll l, ll r, T t) {
    auto it1 = divide(l);
    auto it2 = divide(r);
    auto it = it1;
    it->second = t;
    for (it++; it != it2; it = repl.erase(it));
  }

  T get(ll x) const {
    auto it = get_it(x);
    return it->second;
  }

  vector<tuple<ll, ll, T>> get(ll l, ll r) const {
    vector<tuple<ll, ll, T>> ret;
    auto it = get_it(l);
    ll l1 = l;
    while (true) {
      auto it2 = next(it);
      if (r <= it2->first) {
        ret.emplace_back(l1, r, it->second);
        return ret;
      }
      ret.emplace_back(l1, it2->first, it->second);
      it = it2;
      l1 = it->first;
    }
  }

  tuple<ll, ll, T> get_itv(ll x) const {
    auto it = get_it(x);
    auto it2 = next(it);
    return {it->first, it2->first, it->second};
  }

};

// ---- end intervalSet.cc

// @@ !! LIM -- end mark --

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

  
