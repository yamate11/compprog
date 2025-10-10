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

auto func1(ll i) {
  if (i == 0) return 1;
  if (i == 1) return 1;
  return func1(i - 2) + func1(i - 1);
}

int main(int argc, char** argv) {
  auto func2 = [&](auto f, ll i) -> ll {
    if (i == 0) return 1;
    if (i == 1) return 1;
    return f(f, i - 2) + f(f, i - 1);
  };

  function<ll(ll)> func3 = [&](ll i) -> ll {
    if (i == 0) return 1;
    if (i == 1) return 1;
    return func3(i - 2) + func3(i - 1);
  };
}


  ll n = stoll(argv[1]);
  double t1 = get_time_sec();
  ll a = func1(n);
  double t2 = get_time_sec();
  ll b = func2(func2, n);
  double t3 = get_time_sec();
  ll c = func3(n);
  double t4 = get_time_sec();
  
  cerr << t2 - t1 << endl;
  cerr << t3 - t2 << endl;
  cerr << t4 - t3 << endl;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

}
