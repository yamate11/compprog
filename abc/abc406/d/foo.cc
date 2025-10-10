#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
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

int main() {
  unordered_set<int> uos;
  set<int> os;
  ll N = (ll)1e5;
  REP(i, 0, N) {
    uos.insert(i);
    os.insert(i);
  }
  uos = unordered_set<int>();
  double t1 = get_time_sec();
  REP(i, 0, N) {
    uos.clear();
    // uos = unordered_set<int>();
  }
  double t2 = get_time_sec();
  REP(i, 0, N) {
    os.clear();
  }
  double t3 = get_time_sec();

  cout << t2 - t1 << endl;
  cout << t3 - t2 << endl;

}
