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

// @@ !! LIM(random)

// ---- inserted library file random.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/random.cc


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

  double rand(double a, double b) {
    if (!(a <= b)) {
      throw std::runtime_error("Random.rand: invalid range");
    }
    std::uniform_real_distribution<double> dist(a, b);
    return dist(rng);
  }

  pair<ll, ll> select2(ll i, ll j) {
    if (j - i < 2) {
      throw std::runtime_error("Random.select2: range too small");
    }
    ll x = range(i, j);
    ll y = range(i, j - 1);
    if (y >= x) ++y;
    if (x > y) swap(x, y);
    return {x, y};
  }

  template<typename RandomIt>
  void shuffle(RandomIt first, RandomIt last) { std::shuffle(first, last, rng); }

};

random_device Random::the_random_device;

// ---- end random.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if DEBUG
  ll K0 = 3;
#else
  ll K0 = 30;
#endif

  Random myr;

  auto solve = [&]() -> void {
    auto ask = [&](ll a, ll b) -> ll {
      cout << a << " " << b << endl;
      ll r; cin >> r;
      return r;
    };

    ll x = 1; 
    cout << x << endl;
    ll p; cin >> p;
    ll y = p ^ 1;
    if (y & 1) {
      ll z = ask(0, 1);
      cout << (z & 1) << endl;
      return;
    }
    if (y != 0) {
      ll k = countr_zero((u64)y);
      ll z = ask(0, 1LL << k);
      if (z >> k & 1) cout << 0 << endl;
      else cout << 1 << endl;
      return;
    }
    ll m0 = 0, m1 = 0;
    REP(i, 0, K0 - 1) {
      ll a0 = myr.range(0, 2);
      ll a1 = myr.range(0, 2);
      m0 = 2 * m0 + a0;
      m1 = 2 * m1 + a1;
    }
    m0 = 2 * m0 + 0;
    m1 = 2 * m1 + 1;
    ll z = ask(m0, m1);
    ll ans = -1;
    if ((m0 ^ z) <= 1) ans = 0;
    else if ((m1 ^ z) <= 1) ans = 1;
    else if (z & 1) ans = 0;
    else ans = 1;
    cout << ans << endl;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

