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

// @@ !! LIM(input binsearch)

// ---- inserted library file input.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted library file binsearch.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/binsearch.cc

template <typename T>
requires integral<T>
T binsearch(auto check, T yes, T no) {
  while (abs(no - yes) > 1) {
    T mid = yes + (no - yes) / 2;  // avoiding unnecessary overflow
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template <typename T>
requires floating_point<T>
T binsearch(auto check, T yes, T no, T err, const bool abs_only = false) {
  T rep_in_t = ceil(log(abs(yes - no) / err) / log(2.0));
  constexpr int lim = INT_MAX - 10;
  int rep = rep_in_t > (T)lim ? lim : llround(rep_in_t) + 1;
  for (int r = 0; r < rep; r++) {
    T mid = (yes + no) / 2.0;
    if (not abs_only) {
      if (abs(yes - mid) < err * min(abs(mid), abs(yes))) return mid;
    }
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, fwd, dec=1, dir=True, read=(B, C)) [EoFqBTzB]
  struct fwd_t {
    int nd;
    ll B;
    ll C;
    string show() const {
      return "(" + to_string(nd) + ", " + to_string(B) + ", " + to_string(C) + ")";
    }
    bool operator==(const fwd_t&) const = default;
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll B; cin >> B;
    ll C; cin >> C;
    fwd[u].emplace_back(v, B, C);
  }
  // @End [EoFqBTzB]

  double big = 1e18;
  auto check = [&](double goal) -> bool {
    vector<optional<double>> tbl(N);
    auto f = [&](auto rF, ll nd) -> double {
      optional<double>& r = tbl[nd];
      if (not r) {
        if (nd == N - 1) r = 0.0;
        else {
          r = -big;
          for (auto [peer, b, c] : fwd[nd]) {
            double e = b - goal * c + rF(rF, peer);
            r = max(*r, e);
          }
        }
      }
      return *r;
    };
    return f(f, 0) >= 0.0;
  };
  double ans = binsearch<double>(check, 0.0, 1.1e4, 1e-10);
  cout << ans << endl;
  return 0;
}

