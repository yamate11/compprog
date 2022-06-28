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

// @@ !! LIM(mypair)

// ---- inserted library file mypair.cc

template<typename A, typename B>
struct mypair {
  A _1;
  B _2;
  mypair() : _1(), _2() {}
  mypair(const A& a, const B& b) : _1(a), _2(b) {}
  mypair(A&& a, B&& b) : _1(forward<A>(a)), _2(forward<B>(b)) {}
  mypair(const mypair& o) : _1(o._1), _2(o._2) {}
  mypair(mypair&& o) : _1(move(o._1)), _2(move(o._2)) {}

  mypair& operator =(const mypair& o) { _1 = o._1; _2 = o._2; return *this; }
  mypair& operator =(mypair&& o) { _1 = move(o._1); _2 = move(o._2); return *this; }

  bool operator ==(const mypair& o) const { return _1 == o._1 and _2 == o._2; }
  bool operator !=(const mypair& o) const { return not (*this == o); }
  bool operator  <(const mypair& o) const { return _1 < o._1 or (_1 == o._1 and _2 < o._2); }
  bool operator  >(const mypair& o) const { return o < *this; }
  bool operator <=(const mypair& o) const { return not (*this > o); }
  bool operator >=(const mypair& o) const { return o <= *this; }

  mypair(const pair<A, B>& p) : _1(p.first), _2(p.second) {}

  friend istream& operator >>(istream& is, mypair& p) { is >> p._1 >> p._2; return is; }
  friend ostream& operator <<(ostream& os, const mypair& p) { os << "(" << p._1 << ", " << p._2 << ")"; return os; }

  mypair& operator +=(const mypair& o) { _1 += o._1; _2 += o._2; return *this; }
  mypair& operator -=(const mypair& o) { _1 -= o._1; _2 -= o._2; return *this; }
  mypair& operator *=(const A& a) { _1 *= a; _2 *= a; return *this; }
  mypair& operator /=(const A& a) { _1 /= a; _2 /= a; return *this; }
  mypair operator +(const mypair& o) const { mypair ret(*this); ret += o; return ret; }
  mypair operator -() const { return mypair(-_1, -_2); }
  mypair operator -(const mypair& o) const { mypair ret(*this); ret -= o; return ret; }
  mypair operator *(const A& a) const { mypair ret(*this); ret *= a; return ret; }
  friend mypair operator*(const A& a, mypair& p) { return mypair(a * p._1, a * p._2); }
  mypair operator /(const A& a) const { mypair ret(*this); ret /= a; return ret; }
  
  int mod4(ll r) {
    ll t = r % 4;
    return t >= 0 ? t : 4 + t;
  }
  void self_rotate(ll r = 1) {
    ll t = mod4(r);
    if (t == 0) return;
    if (t == 1) { swap(_1, _2); _1 = -_1; }
    if (t == 2) { _1 = -_1; _2 = -_2; }
    if (t == 3) { swap(_1, _2); _2 = -_2; }
  }
  mypair rotate(ll r = 1) const {
    mypair ret(*this);
    ret.self_rotate(r);
    return ret;
  }

  A inner_prod(const mypair& o) const { return _1 * o._1 + _2 * o._2; }
  bool parallel(const mypair& o) const { return _1 * o._2 == _2 * o._1; }

};

using pll = mypair<ll, ll>;

// ---- end mypair.cc

// @@ !! LIM -- end mark --



int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X;
  vector<ll> num(N + 1);
  num[0] = 1;
  REP(i, N) num[i + 1] = 2 * num[i] + 3;
  ll patty = 0;
  ll rem = X;
  map<pll, pll> tbl;
  auto func = [&](auto rF, ll lev) -> pll {
    if (lev == 0) { patty++; rem--; return; }
    ll x = min(rem, num[n]);

    auto calc = [&]() -> pll {
      ll patty = 0;
      ll total = 0;
      total++;
      if (x <= total) return pll(patty, total);
      {
        auto [p, t] = rF(rF, n - 1, x - total);
        patty += p;
        total += t;
      }
      if (x <= total) return pll(patty, total);
      patty += 1;
      total += 1;
      if (x <= total) return pll(patty, total);
      {
        auto [p, t] = rF(rF, n - 1, x - total);
        patty += p;
        total += t;
      }
      if (x <= total) return pll(patty, total);
      total += 1;
      assert(x <= total);
      return pll(patty, total);
    };

    auto it = tbl.find(pll(n, x));
    if (it != tbl.end()) return it->second;
    return tbl[pll(n, x)] = calc();

  };
  cout << func(func, N, X)._1 << endl;

  return 0;
}

