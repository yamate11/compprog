#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(f:updMaxMin f:itrange)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

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

#define ALLIR(a, b) ItRange(a, b).begin(), ItRange(a, b).end()

// Imitation to Python range operator....


// ---- end f:itrange

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<string> b(N);
  REP(i, N) cin >> b[i];
  auto tbl = vector(N, vector(N + 1, vector(N, vector(N + 1, -1LL))));
  auto blR = [&](ll r, ll c1, ll c2) -> bool {
    ItRange ir(c1, c2);
    return all_of(ALL(ir), [&](ll c) -> bool {return b[r][c] == '.';});
  };
  auto blC = [&](ll c, ll r1, ll r2) -> bool {
    ItRange ir(r1, r2);
    return all_of(ALL(ir), [&](ll r) -> bool {return b[r][c] == '.';});
  };
    

  auto func = [&](auto rF, ll r1, ll r2, ll c1, ll c2) -> ll {
    if (r1 == r2 or c1 == c2) return 0;
    ll& ret = tbl[r1][r2][c1][c2];
    if (ret < 0) {
      if      (blR(r1,     c1, c2)) ret = rF(rF, r1 + 1, r2, c1, c2);
      else if (blR(r2 - 1, c1, c2)) ret = rF(rF, r1, r2 - 1, c1, c2);
      else if (blC(c1,     r1, r2)) ret = rF(rF, r1, r2, c1 + 1, c2);
      else if (blC(c2 - 1, r1, r2)) ret = rF(rF, r1, r2, c1, c2 - 1);
      else {
        ret = max(r2 - r1, c2 - c1);
        REP2(r, r1 + 1, r2 - 1) if (blR(r, c1, c2)) updMin(ret, rF(rF, r1, r, c1, c2) + rF(rF, r + 1, r2, c1, c2));
        REP2(c, c1 + 1, c2 - 1) if (blC(c, r1, r2)) updMin(ret, rF(rF, r1, r2, c1, c) + rF(rF, r1, r2, c + 1, c2));
      }
    }
    return ret;
  };
  cout << func(func, 0, N, 0, N) << endl;

  return 0;
}

