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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

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

ll c1 = 7823443284326134;
ll c2 = 4890572832174934;
ll d1 = 1948390984293047;
ll d2 = 7013984319432424;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double t1 = get_time_sec();
  ll t = 0;
  REP(i, 0, 1e8) {
    ll y = i * c1 + d1;
    ll x = i * c2 + d2;
    if (y == 0) y = 1;
    ll z = x + y;
    t += z;
  }
  double t2 = get_time_sec();
  cout << t2 - t1 << endl;
  cout << t << endl;

  return 0;
}

