#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(f:perfmeas)

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

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  ll n = 100000;
  vector<ll> vec(n);
  set<ll> ss;
  REP(i, 0, n) {
    ll x = randrange(0, 1LL << 40);
    vec[i] = x;
    ss.insert(i);
  }
  vector<ll> pos(n);
  vector<ll> vals(n);
  REP(i, 0, n) {
    pos[i] = randrange(0, n);
    vals[i] = randrange(0, 1LL << 40);
  }
  double t0 = get_time_sec();
  REP(i, 0, n) {
    vec.insert(vec.begin() + pos[i], vals[i]);
    vec.pop_back();
  }
  double t1 = get_time_sec();
  REP(i, 0, n) {
    ss.insert(vals[i]);
    ss.erase(prev(ss.end()));
  }
  double t2 = get_time_sec();
  unsigned long long a = 0;
  REP(j, 0, n / 2) {
    REP(i, 0, n) {
      a += (unsigned long long)vals[i ^ j];
    }
  }
  double t3 = get_time_sec();

  cout << 1000 * (t1 - t0) << endl;
  cout << 1000 * (t2 - t1) << endl;
  cout << 1000 * (t3 - t2) << endl;
  
  cout << a << endl;

  return 0;
}

