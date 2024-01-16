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

template<typename F>
struct A {
  F f;
  A(F f_) : f(f_) {}
};

struct B {
  function<ll(ll)> f;
  B(function<ll(ll)> f_) : f(f_) {}
};

const int primeB = 998'244'353;
const int a1 = 9923;
const int a2 = 4259;

ll func1a(ll x) { return a1 * x + a2; }
ll func2a(ll x) { return (a1 * x + a2) % primeB; }

// auto add1 = [&](ll x) -> ll { return (5 * x + 2) % primeB; };

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto func1b = [](ll x) -> ll { return a1 * x + a2; };
  auto func2b = [](ll x) -> ll { return (a1 * x + a2) % primeB; };

  ll rep = 1LL<<26;

  ll icode = atoi(argv[1]);
  if (icode == 1) {
    ll x = 1;
    double t1 = get_time_sec();
    for (ll i = 0; i < rep; i++) { x = a1 * x + a2; }
    double t2 = get_time_sec();
    cout << t2 - t1 << endl;
    cerr << x << endl;
  }
  if (icode == 2) {
    ll x = 1;
    A<decltype(*func1a)> a(*func1a);
    double t1 = get_time_sec();
    for (ll i = 0; i < rep; i++) x = a.f(x);
    double t2 = get_time_sec();
    cout << t2 - t1 << endl;
    cerr << x << endl;
  }
  if (icode == 3) {
    ll x = 1;
    A<decltype(func1b)> a(func1b);
    double t1 = get_time_sec();
    for (ll i = 0; i < rep; i++) x = a.f(x);
    double t2 = get_time_sec();
    cout << t2 - t1 << endl;
    cerr << x << endl;
  }
  if (icode == 4) {
    ll x = 1;
    B a(func1a);
    double t1 = get_time_sec();
    for (ll i = 0; i < rep; i++) x = a.f(x);
    double t2 = get_time_sec();
    cout << t2 - t1 << endl;
    cerr << x << endl;
  }
  if (icode == 5) {
    ll x = 1;
    B a(func1b);
    double t1 = get_time_sec();
    for (ll i = 0; i < rep; i++) x = a.f(x);
    double t2 = get_time_sec();
    cout << t2 - t1 << endl;
    cerr << x << endl;
  }
  return 0;
}

