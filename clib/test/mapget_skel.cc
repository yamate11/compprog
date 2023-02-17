#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mapget f:perfmeas)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {

    mgs<map<ll, ll>> mp;
    mp[0] = 1;
    mp[10] = 3;
    mp[100] = 5;

    assert(mp.get(10) == 3);
    assert(mp.get(20) == 0);
    assert(mp.find(20) == mp.end());

    mgs<map<ll, ll>> mp1(mp);
    mp1[1000] = 7;

    assert(mp1.get(100) == 5);
    assert(mp1.get(1000) == 7);
    assert(mp1.get(30) == 0);
    assert(mp1.find(30) == mp1.end());

    mgs<map<ll, ll>> mp2(move(mp1));
    mp2[10000] = 9;

    assert(mp2.get(1000) == 7);
    assert(mp2.get(10000) == 9);
    assert(mp2.get(40) == 0);

    mp2.set(10, -3);
    assert(mp2.get(10) == -3);
    mp2.set(100, 0);
    assert(mp2.get(100) == 0);
    assert(mp2.find(100) == mp2.end());

  }

  {
    mgs<unordered_map<ll, ll>> mp;
    mp[0] = 1;
    mp[10] = 3;
    mp[100] = 5;

    assert(mp.get(10) == 3);
    assert(mp.get(20) == 0);
    assert(mp.find(20) == mp.end());

    mgs<unordered_map<ll, ll>> mp1(mp);
    mp1[1000] = 7;

    assert(mp1.get(100) == 5);
    assert(mp1.get(1000) == 7);
    assert(mp1.get(30) == 0);
    assert(mp1.find(30) == mp1.end());

    mgs<unordered_map<ll, ll>> mp2(move(mp1));
    mp2[10000] = 9;

    assert(mp2.get(1000) == 7);
    assert(mp2.get(10000) == 9);
    assert(mp2.get(40) == 0);

    mp2.set(10, -3);
    assert(mp2.get(10) == -3);
    mp2.set(100, 0);
    assert(mp2.get(100) == 0);
    assert(mp2.find(100) == mp2.end());

  }

  {  // move constructor
    ll lim = 3000;
    mgs<map<ll, vector<ll>>> mp;
    for (ll i = 0; i < lim; i++) mp[i] = vector(lim, 0LL);
    double t0 = get_time_sec();
    mgs<map<ll, vector<ll>>> mp1(mp);
    double t1 = get_time_sec();
    mgs<map<ll, vector<ll>>> mp2(move(mp));
    double t2 = get_time_sec();
    assert((t1 - t0) > 3 * (t2 - t1));
  }

  {  // get returns a reference, not a copy
    mgs<map<ll, vector<ll>>> mp;
    ll lim = 3000;
    for (ll i = 0; i < lim; i++) mp.set(i, vector<ll>(lim));
    double t0 = get_time_sec();
    ll s = 0;
    for (ll i = 0; i < lim; i++) {
      auto& v = mp.get(i);
      s += v[i];
    }
    double t1 = get_time_sec();
    s = 0;
    for (ll i = 0; i < lim; i++) {
      auto v = mp.get(i);
      s += v[i];
    }
    double t2 = get_time_sec();
    assert((t2 - t1) > 3 * (t1 - t0));
  }

  { // set employs the move semantics
    mgs<map<ll, vector<ll>>> mp;
    ll lim = 3000;
    vector vec(lim, vector(lim, 0LL));
    double t0 = get_time_sec();
    for (ll i = 0; i < lim; i++) mp.set(i, vec[i]);
    double t1 = get_time_sec();
    for (ll i = 0; i < lim; i++) mp.set(i, move(vec[i]));
    double t2 = get_time_sec();
    assert((t1 - t0) > 3 * (t2 - t1));
  }

  { // substitution
    mgs<map<ll, ll>> mp1(0);
    mp1.set(10, 100);
    mp1.set(20, 400);
    mgs<map<ll, ll>> mp2(-1);
    mp2.set(30, 900);
    assert((mp2.get(0) == -1));
    assert((mp2.get(30) == 900));
    mp2 = mp1;
    assert((mp2.get(0) == 0));
    assert((mp2.get(30) == 0));
    assert((mp2.get(10) == 100));
  }

  { // move substitution
    mgs<map<ll, ll>> mp1(0);
    mp1.set(10, 100);
    mp1.set(20, 400);
    mgs<map<ll, ll>> mp2(-1);
    mp2.set(30, 900);
    assert((mp2.get(0) == -1));
    assert((mp2.get(30) == 900));
    mp2 = move(mp1);
    assert((mp2.get(0) == 0));
    assert((mp2.get(30) == 0));
    assert((mp2.get(10) == 100));

    // move semantics check by performance
    ll lim = 3000;
    mgs<map<ll, vector<ll>>> mp;
    for (ll i = 0; i < lim; i++) mp[i] = vector(lim, 0LL);
    double t0 = get_time_sec();
    auto mp3 = mp;
    double t1 = get_time_sec();
    auto mp4 = move(mp);
    double t2 = get_time_sec();
    assert((t1 - t0) > 3 * (t2 - t1));
  }

  // translation from older testsets
  {
    mgs<map<ll, ll>> mp;
    mp.set(1, 5);
    mp.set(7, -1);
    assert(mp.get(1) == 5);
    assert(mp.get(7) == -1);
    assert(mp.get(100) == 0);
    assert(mp.find(100) == mp.end());
    mp.set(4, 2);
    assert(mp.get(4) == 2);
    mp.set(7, 0);
    assert(mp.get(7) == 0);
    assert(mp.find(7) == mp.end());
  }
  {
    mgs<map<ll, ll>> mp;
    mp.set(1, 1); // constant
    ll x = 2;
    mp.set(2, x); // l-value
    const ll y = 3;
    mp.set(3, y); // const l-value
    mp.set(4, move(x)); // r-value
    assert(mp.get(1) == 1);
    assert(mp.get(2) == 2);
    assert(mp.get(3) == 3);
    assert(mp.get(4) == 2);
  }
  {
    using vi = vector<int>;
    mgs<map<int, vi>> mp;
    mp.set(3, vi{1, 2, 3});
    mp.set(7, move(vi{-1, -2}));
    mp.set(10, vi{});
    assert(mp.get(3) == (vi{1, 2, 3}));
    assert(mp.get(7) == (vi{-1, -2}));
    assert(mp.get(10) == vi{});
    assert(mp.get(100000) == vi{});
    assert(mp.find(10) == mp.end());
    mp.set(7, vi{});
    assert(mp.size() == 1);
  }
  {
    mgs<map<int, string>> mp("---");
    mp.set(4, "");
    mp.set(5, "hello");
    mp.set(2, "world");
    mp.set(7, "---");
    assert(mp.get(2) == "world");
    assert(mp.get(7) == "---");
    assert(mp.get(-10) == "---");
  }

  return 0;
}

