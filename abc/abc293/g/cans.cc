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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [lNdVoOxk]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [lNdVoOxk]
  // @InpMVec(Q, ((L, dec=1), (R, dec=0))) [0c4yOWof]
  auto L = vector(Q, ll());
  auto R = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 0; R[i] = v2;
  }
  // @End [0c4yOWof]

  ll K = llround(sqrt(Q));
  ll width = divCeil(N, K);
  vector ord(Q, 0LL);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](ll i, ll j) -> bool {
    ll ti = L[i] / width;
    ll tj = L[j] / width;
    if (ti != tj) return ti < tj;
    return R[i] < R[j];
  });
  auto f = [&](ll x) -> ll { return x * (x - 1) * (x - 2) / 6; };
  ll l = 0, r = 0;
  ll val = 0;
  ll lim = (ll)(2e5) + 1;
  vector<ll> cnt(lim, 0LL);
  vector<ll> ans(Q);
  REP(ii, 0, Q) {
    ll i = ord[ii];
    while (r < R[i]) {
      ll w = A[r];
      val -= f(cnt[w]);
      cnt[w]++;
      val += f(cnt[w]);
      r++;
    }
    while (R[i] < r) {
      r--;
      ll w = A[r];
      val -= f(cnt[w]);
      cnt[w]--;
      val += f(cnt[w]);
    }
    while (L[i] < l) {
      l--;
      ll w = A[l];
      val -= f(cnt[w]);
      cnt[w]++;
      val += f(cnt[w]);
    }
    while (l < L[i]) {
      ll w = A[l];
      val -= f(cnt[w]);
      cnt[w]--;
      val += f(cnt[w]);
      l++;
    }
    ans[i] = val;
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

