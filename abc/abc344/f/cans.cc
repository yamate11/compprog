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

// @@ !! LIM(mapget f:intDiv)

// ---- inserted library file mapget.cc

template<typename MP>
struct mgs : MP {
  using Key = typename MP::key_type;
  using T = typename MP::mapped_type;

  T def;

  mgs(const T& def_ = T()) : MP(), def(def_) {}
  mgs(const mgs& o) : MP(o), def(o.def) {}
  mgs(mgs&& o) : MP(move(o)), def(move(o.def)) {}
  mgs& operator =(const mgs& o) {
    MP::operator=(o);
    def = o.def;
    return *this;
  }
  mgs& operator =(mgs&& o) {
    MP::operator=(move(o));
    def = move(o.def);
    return *this;
  }

  const T& get(const Key& k) const {
    auto it = this->find(k);
    if (it == this->end()) return def;
    else return it->second;
  }

  template<typename T1>
  void set(const Key& k, T1&& t) {
    if (t == def) this->erase(k);
    else (*this)[k] = forward<T1>(t);
  }
};

// ---- end mapget.cc

// ---- inserted function f:intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end f:intDiv

// @@ !! LIM -- end mark --

struct myP {
  ll num;
  ll money;
  myP(ll num_ = 0, ll money_ = 0) : num(num_), money(money_) {};
  bool operator <(const myP& o) const {
    if (num != o.num) return num < o.num;
    else return money > o.money;
  }
};



int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpGrid(N, N, P) [2LTkrzup]
  auto P = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; P[i][j] = v; }
  // @End [2LTkrzup]
  // @InpGrid(N, N - 1, R) [9tCcu6xw]
  auto R = vector(N, vector(N - 1, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N - 1; j++) { ll v; cin >> v; R[i][j] = v; }
  // @End [9tCcu6xw]
  // @InpGrid(N - 1, N, D) [gv1iN05q]
  auto D = vector(N - 1, vector(N, ll()));
  for (int i = 0; i < N - 1; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; D[i][j] = v; }
  // @End [gv1iN05q]

  ll big = 1e18;

  using mymap = mgs<unordered_map<ll, myP>>;
  vector tbl(N, vector(N, mymap(myP(big, 0))));
  tbl[0][0][0] = myP(0, 0);
  REP(i, 0, N) REP(j, 0, N) {
    for (auto [w, p] : tbl[i][j]) {
      ll ww = max(w, P[i][j]);
      if (i + 1 < N) {
        auto& mp = tbl[i + 1][j];
        ll k = D[i][j] <= p.money ? 0 : divCeil(D[i][j] - p.money, ww);
        mp[ww] = min(mp.get(ww), myP(p.num + k + 1, p.money + ww * k - D[i][j]));
      }
      if (j + 1 < N) {
        auto& mp = tbl[i][j + 1];
        ll k = R[i][j] <= p.money ? 0 : divCeil(R[i][j] - p.money, ww);
        mp[ww] = min(mp.get(ww), myP(p.num + k + 1, p.money + ww * k - R[i][j]));
      }
    }
  }
  ll ans = big;
  for (auto [w, p] : tbl[N - 1][N - 1]) ans = min(ans, p.num);
  cout << ans << endl;

  return 0;
}

