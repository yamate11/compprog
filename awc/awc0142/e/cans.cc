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

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/input.cc

// The contents are empty.

// ---- end input.cc

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

// @@ !! LIM -- end mark --

// @DefStruct(sta, (tr_num, pct), ord=(tr_num, pct)) [P9szwbQu]
struct sta {
  ll tr_num;
  ll pct;
  string show() const {
    return "(" + to_string(tr_num) + ", " + to_string(pct) + ")";
  }
  strong_ordering operator<=>(const sta& o) const {
    if (auto r_ = tr_num <=> o.tr_num; r_ != 0) return r_;
    if (auto r_ = pct <=> o.pct; r_ != 0) return r_;
    return std::strong_ordering::equal;
  }
  bool operator==(const sta&) const = default;
};
// @End [P9szwbQu]

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpVec(N, W) [Ju6CX97m]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [Ju6CX97m]
  
  vector tbl(1LL << N, sta(N + 1, 0));
  tbl[0] = sta{0, 0};
  REP(x, 1, 1LL << N) {
    REP(i, 0, N) if (x >> i & 1) {
      ll y = x ^ (1LL << i);
      auto [t, p] = tbl[y];
      if (p + W[i] <= M) updMin(tbl[x], sta{t, p + W[i]});
      else updMin(tbl[x], sta{t + 1, W[i]});
    }
  }
  ll full = (1LL << N) - 1;
  auto [t, p] = tbl[full];
  if (p > 0) t++;
  cout << t << "\n";


  return 0;
}

