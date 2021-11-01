#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:itrange f:perfmeas)

// ---- inserted function f:itrange from util.cc

struct ItRange {
  ll st;
  ll en;

  struct Itr {
    using iterator_category = input_iterator_tag;
    using value_type = ll;
    using difference_type = ptrdiff_t;
    using reference = value_type const&;
    using pointer = value_type const*;

    ll val;

    bool operator ==(const Itr& o) const { return val == o.val; }
    bool operator !=(const Itr& o) const { return val != o.val; }

    reference operator *() const { return val; }
    pointer operator ->() const { return &val; }

    Itr& operator ++() {
      val++;
      return *this;
    }
    Itr operator ++(int) {
      Itr const tmp(*this);
      ++*this;
      return tmp;
    }

  };

  ItRange(ll v_start, ll v_end): st(v_start), en(v_end) {}
  Itr begin() { return Itr({st}); }
  Itr end() { return Itr({en}); }
};

// Imitation to Python range operator....


// ---- end f:itrange

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --



#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define ALLIR(a, b) ItRange(a, b).begin(), ItRange(a, b).end()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll sz = 100;
  ll nc = 100000;
  vector<string> s(nc);
  REP(i, nc) s[i] = string(sz, '0');
  
  /*
  ll cnt = 0;
  {
    bool b = all_of(ALLIR(0, sz), [&](ll j) { return s[0][j] == '0'; });
    if (b) cnt++;
  }
  */
  double t1 = get_time_sec();
  ItRange itr(0, sz);
  ll cnt0 = 0;
  REP(i, nc) {
    bool b = all_of(ALL(itr), [&](ll j)  { return s[i][j] == '0'; });
    if (b) cnt0 ++;
  }
  double t2 = get_time_sec();
  ll cnt1 = 0;
  REP(i, nc) {
    bool b = all_of(ALLIR(0, sz), [&](ll j) { return s[i][j] == '0'; });
    if (b) cnt1 ++;
  }
  double t3 = get_time_sec();
  ll cnt2 = 0;
  REP(i, nc) {
    bool b = true;
    REP(j, sz) if (s[i][j] != '0') { b = false;  break; }
    if (b) cnt2 ++;
  }
  double t4 = get_time_sec();
  cerr << t2 - t1 << endl;
  cerr << t3 - t2 << endl;
  cerr << t4 - t3 << endl;
  assert(cnt0 == cnt1);
  assert(cnt1 == cnt2);

  return 0;
}

