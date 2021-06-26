#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

struct ll_range {
  ll bg;
  ll en;

  struct itr {
    ll cur;
    // bool operator ==(const itr& o) { return cur == o.cur; }
    bool operator !=(const itr& o) const { return cur != o.cur; }
    ll operator *() const { return cur; }
    void operator ++() { cur++; }
  };

  ll_range(ll b, ll e) : bg(b), en(e) {}
  itr begin() { return {bg}; }
  itr end() { return {en}; }

};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll p = atoi(argv[1]);
  ll rep = 1LL << p;

  ll acc = 0;

  double t1 = get_time_sec();
  ll_range rng(0, rep);
  for (auto x : rng) {
    acc |= x;
  }
  double t2 = get_time_sec();
  for (ll i = 0; i < rep; i++) {
    acc |= i;
  }
  double t3 = get_time_sec();


  cout << t2 - t1 << endl;
  cout << t3 - t2 << endl;
  cout << acc << endl;

  return 0;
}

