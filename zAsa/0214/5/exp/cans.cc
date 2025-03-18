#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(random f:perfmeas)

// ---- inserted library file random.cc


struct Random {
  static random_device the_random_device;
  mt19937_64 rng;

  Random() : rng(the_random_device()) {}
  Random(unsigned seed) : rng(seed) {}
  
  ll range(ll i, ll j) {
    if (i >= j) {
      throw runtime_error("Random.range: invalid range");
    }
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  }

};

random_device Random::the_random_device;

// ---- end random.cc

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    map<int, int> mp;
    mp[3] = 30;
    mp[5] = 50;
    auto [it1, b1] = mp.insert_or_assign(4, 400);
    assert(b1 == true and it1->first == 4 and it1->second == 400);
    auto [it2, b2] = mp.insert_or_assign(5, 500);
    assert(b2 == false and it2->first == 5 and it2->second == 500);
  }
  {
    map<int, int> mp;
    mp[3] = 30;
    mp[5] = 50;
    auto [it1, b1] = mp.emplace(4, 400);
    assert(b1 == true and it1->first == 4 and it1->second == 400);
    auto [it2, b2] = mp.emplace(5, 500);
    assert(b2 == false and it2->first == 5 and it2->second == 50);
  }
  {
    auto func1 = [&](auto& mp, int s, int t) {
      auto it = mp.lower_bound(s);
      if (it != mp.end() and it->first == s) {
        return make_pair(it, false);
      }else if (s % 2 == 0) {
        auto it2 = mp.emplace_hint(it, s, t);
        return make_pair(it2, true);
      }else {
        return make_pair(mp.end(), false);
      }
    };

    map<int, int> mp;
    mp[3] = 30;
    mp[5] = 50;
    auto [it1, b1] = func1(mp, 4, 400);
    assert(b1 == true and it1->first == 4 and it1->second == 400);
    auto [it2, b2] = func1(mp, 1, 100);
    assert(b2 == false and it2 == mp.end());
    auto [it3, b3] = func1(mp, 3, 300);
    assert(b3 == false and it3->first == 3 and it3->second == 30);
  }

#if 0
  {
    Random rand;
    auto func2_naive = [&](auto& mp, int s, int t) {
      if (mp.find(s) == mp.end()) mp[s] = t;
    };
    auto func2_ok = [&](auto& mp, int s, int t) {
      mp.emplace(s, t);
    };
    ll k; cin >> k;
    ll N = 1LL << k;
    vector<int> vs, vt;
    for (int i = 0; i < N; i++) {
      vs.push_back(rand.range(0, 2 * N));
      vt.push_back(rand.range(0, 2 * N));
    }
    double t1 = get_time_sec();
    map<int, int> mp1;
    for (int i = 0; i < N; i++) {
      func2_naive(mp1, vs[i], vt[i]);
    }
    double t2 = get_time_sec();
    map<int, int> mp2;
    for (int i = 0; i < N; i++) {
      func2_ok(mp2, vs[i], vt[i]);
    }
    double t3 = get_time_sec();
    cout << "func2_naive:  " << t2 - t1 << endl;
    cout << "func2_ok:     " << t3 - t2 << endl;
  }
#endif

#if 1
  {
    Random rand;
    auto func3_naive = [&](auto& mp, int s, int t) {
      if (mp.find(s) == mp.end() and s % 2 == 0) mp[s] = t;
    };
    auto func3_ok = [&](auto& mp, int s, int t) {
      auto it = mp.lower_bound(s);
      if ((it == mp.end() or it->first != s) and s % 2 == 0) mp.emplace_hint(it, s, t);
    };
    ll k; cin >> k;
    ll N = 1LL << k;
    vector<int> vs, vt;
    for (int i = 0; i < N; i++) {
      vs.push_back(rand.range(0, 2 * N));
      vt.push_back(rand.range(0, 2 * N));
    }
    double t1 = get_time_sec();
    map<int, int> mp1;
    for (int i = 0; i < N; i++) {
      func3_naive(mp1, vs[i], vt[i]);
    }
    double t2 = get_time_sec();
    map<int, int> mp2;
    for (int i = 0; i < N; i++) {
      func3_ok(mp2, vs[i], vt[i]);
    }
    double t3 = get_time_sec();
    cout << "func3_naive:  " << t2 - t1 << endl;
    cout << "func3_ok:     " << t3 - t2 << endl;
  }
#endif

  return 0;
}

