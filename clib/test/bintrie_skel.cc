#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(bintrie)

int main() {

  {
    BinTrie bt(4);
  
    bt.insert(10);
    bt.insert(2);
    bt.insert(7);
    bt.insert(13);
    {
      stringstream ss;
      ss << bt;
      assert(ss.str() == "[2:1, 7:1, 10:1, 13:1]");
    }
    bt.erase(2);
    {
      stringstream ss;
      ss << bt;
      assert(ss.str() == "[7:1, 10:1, 13:1]");
    }
    assert(bt.find(7) == 1);
    assert(bt.find(2) == 0);
    assert(bt.erase_safe(4) == 0);
    assert(bt.num_le(6) == 0);
    assert(bt.num_le(7) == 1);
    assert(bt.num_le(9) == 1);
    assert(bt.num_le(10) == 2);
    assert(bt.num_le(15) == 3);
    assert(bt.num_le(-100000) == 0);
    assert(bt.num_le(100000) == 3);
    assert(bt.num_lt(7) == 0);
    assert(bt.num_lt(8) == 1);
    assert(bt.kth(0) == 7);
    assert(bt.kth(1) == 10);
    assert(bt.kth(2) == 13);
    assert(bt.kth(3) == -1);
    assert(bt.lower_bound(0) == 7);
    assert(bt.lower_bound(7) == 7);
    assert(bt.lower_bound(8) == 10);
    assert(bt.lower_bound(13) == 13);
    assert(bt.lower_bound(14) == -1);
  }

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    ll nbit = 4;
    BinTrie bt(nbit);
    vector<int> vec(1LL << nbit);

    auto get_x = [&]() -> int { return randrange(0, 1LL << nbit); };
    auto t_insert = [&](int x, int num) -> void {
      bt.insert(x, num);
      vec[x] += num;
    };
    auto t_erase_safe = [&](int x, int num) -> void {
      int a = bt.erase_safe(x, num);
      assert(a == min(num, vec[x]));
      vec[x] -= a;
    };

    int rep = 1000;
    int rep2 = 30;  // 30 or something should be appropriate
    int mode = 0;
    for (int i = 0; i < rep; i++) {
      for (int j = 0; j < rep2; j++) {
        {
          int num = randrange(1, 4);
          int x = get_x();
          if (mode == 0) {
            if (randrange(0, 100) < 90) t_insert(x, num);
            else t_erase_safe(x, num);
          }else {
            if (randrange(0, 100) < 90) t_erase_safe(x, num);
            else t_insert(x, num);
          }
        }
        int tp = randrange(0, 4);
        if (tp == 0) {
          int x = get_x();
          assert(bt.find(x) == vec[x]);
        }else if (tp == 1) {
          int x = get_x();
          int s = 0;
          for (int k = 0; k <= x; k++) s += vec[k];
          assert(bt.num_le(x) == s);
        }else if (tp == 2) {
          int k = randrange(0, 2 * rep2);
          ll x = bt.kth(k);
          int m = 0;
          while (m < (int)vec.size() and k >= vec[m]) k -= vec[m++];
          if (m == (int)vec.size()) m = -1;
          assert(x == m);
        }else if (tp == 3) {
          int x = get_x();
          ll a = bt.lower_bound(x);
          ll b = x;
          while (b < (int)vec.size() and vec[b] == 0) b++;
          if (b == (int)vec.size()) b = -1;
          assert(a == b);
        }
      }
      mode = 1 - mode;
    }
  }

  {
    ll nbit = 40;
    BinTrie bt(nbit);
    map<ll, int> mp;

    auto get_x = [&]() -> ll { return randrange(0, 1LL << nbit); };
    auto choose = [&]() -> ll {
      if (mp.empty()) {
        ll y = get_x();
        mp[y] = 1;
        bt.insert(y, 1);
      }
      ll x = get_x();
      auto it = mp.lower_bound(x);
      if (it == mp.end()) it--;
      return it->first;
    };

    int rep = 500;  // 2000, at most.
    int rep2 = 30; // 30 or something should be appropriate
    for (int i = 0; i < rep; i++) {
      for (int j = 0; j < rep2; j++) {
        {
          int num = randrange(1, 4);
          int tp = randrange(0, 100);
          if (tp < 40 ) {
            ll x = get_x();
            bt.insert(x, num);
            mp[x] += num;
            assert(bt.find(x) == mp[x]);
          }else if (tp < 80) {
            ll x = choose();
            bt.insert(x, num);
            mp[x] += num;
            assert(bt.find(x) == mp[x]);
          }else if (tp < 95) {
            ll x = choose();
            ll c = mp[x];
            ll tp2 = randrange(0, 2);
            if (tp2 == 0) {
              ll d = randrange(1, c + 1);
              bt.erase(x, d);
              if (c == d) {
                mp.erase(x);
                assert(bt.find(x) == 0);
              }else {
                mp[x] -= d;
                assert(bt.find(x) == mp[x]);
              }
            }else {
              ll e = bt.erase_safe(x, c * 2);
              mp.erase(x);
              assert(e == c);
              assert(bt.find(x) == 0);
            }
          }else if (tp < 100) {
            ll x = get_x();
            if (mp.find(x) == mp.end()) {
              ll e = bt.erase_safe(x, 10);
              assert(e == 0);
              assert(bt.find(x) == 0);
            }
          }
        }
        int tp = randrange(0, 4);
        if (tp == 0) {
          ll x = choose();
          assert(bt.find(x) == mp[x]);
        }else if (tp == 1) {
          ll x;
          if (randrange(0, 2) == 0) {
            x = get_x();
          }else {
            x = choose();
          }
          int s = 0;
          for (auto [y, c] : mp) {
            if (x < y) break;
            s += c;
          }
          ll t = bt.num_le(x);
          assert(t == s);
        }else if (tp == 2) {
          int k = randrange(0, 2 * rep2);
          ll x = bt.kth(k);
          ll m = -1;
          for (auto [y, c] : mp) {
            if (k < c) { m = y; break; }
            k -= c;
          }
          assert(x == m);
        }else if (tp == 3) {
          ll x = get_x();
          ll a = bt.lower_bound(x);
          auto it = mp.lower_bound(x);
          ll b = it == mp.end() ? -1 : it->first;
          assert(a == b);
        }
      }
    }
  }


}

