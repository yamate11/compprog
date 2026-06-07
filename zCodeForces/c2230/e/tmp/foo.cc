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

  ll sz = 1LL << 20;

  vector<int> vec1;
  vector<int> vec2;

  vec1.resize(sz, 0);
  double t1 = get_time_sec();
  vec1.resize(sz, 0);
  double t2 = get_time_sec();
  REP(i, 0, sz) vec1[i] = i;
  double t3 = get_time_sec();
  vec1.resize(sz, 0);
  double t3a = get_time_sec();

  vec2.reserve(sz);
  double t4 = get_time_sec();
  REP(i, 0, sz) vec2.push_back(i);
  
  double t5 = get_time_sec();

  cout << "resize      " << t2 - t1 << endl;
  cout << "index subst " << t3 - t2 << endl;
  cout << "sum         " << t3 - t1 << endl;
  cout << "again       " << t3a - t3 << endl;
  cout << "reserve     " << t4 - t3 << endl;
  cout << "push_back   " << t5 - t4 << endl;
  cout << "sum         " << t5 - t3 << endl;

  return 0;
}

