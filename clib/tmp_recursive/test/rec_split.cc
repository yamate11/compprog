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

// @@ !! LIM(f:perfmeas random)

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

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

// @@ !! LIM -- end mark --

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  ll N; cin >> N;
  vector nbr(N, vector<ll>());
  REP(i, 0, N - 1) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }

  vector<ll> depth(N);
  vector<ll> stsize(N);

  auto f_both = [&](auto rF, ll nd, ll pt) -> void {
    depth[nd] = pt < 0 ? 0 : depth[pt] + 1;
    stsize[nd] = 1;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
      stsize[nd] += stsize[cld];
    }
  };

  auto f_depth = [&](auto rF, ll nd, ll pt) -> void {
    depth[nd] = pt < 0 ? 0 : depth[pt] + 1;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
  };

  auto f_stsize = [&](auto rF, ll nd, ll pt) -> void {
    stsize[nd] = 1;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
      stsize[nd] += stsize[cld];
    }
  };

  double t1 = get_time_sec();
  f_both(f_both, 0, -1);
  double t2 = get_time_sec();
  f_depth(f_both, 0, -1);
  f_stsize(f_both, 0, -1);
  double t3 = get_time_sec();
  cout << t2 - t1 << endl;
  cout << t3 - t2 << endl;

}
