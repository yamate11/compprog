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

int xx;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ItRange ir(0, 10);
  vector<ll> vec, w;
  for (ll x : ir) vec.push_back(x);
  for (ll i = 0; i < 10; i++) w.push_back(i);
  assert(vec == w);
  vector<ll> vec2;
  bool b1 = all_of(ir.begin(), ir.end(),
                   [&](ll i) -> bool { return i * i < 10000; });
  bool b2 = all_of(ir.begin(), ir.end(),
                   [&](ll i) -> bool { return i * i < 50; });
  bool b3 = any_of(ir.begin(), ir.end(),
                   [&](ll i) -> bool { return i * i > 80; });
  assert(b1 && !b2 && b3);
  

  return 0;
}

