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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(binsearch input)

// ---- inserted library file binsearch.cc

template<typename T>
T binsearch_i(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / 2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template<typename T>
T binsearch_r(auto check, T yes, T no, T err, bool rel = true) {
  while (abs(yes - no) > err &&
         (!rel || abs(yes - no) > abs(yes) * err)) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

ll border_with_hint(ll t, auto pred, auto hint) {
  double y = hint(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = pred(d, t);
  bool re = pred(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = pred(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = pred(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}

// ---- end binsearch.cc

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    // @InpGrid(N, M, A) [PNfxMq9q]
    auto A = vector(N, vector(M, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A[i][j] = v; }
    // @End [PNfxMq9q]
    auto check = [&](ll l) -> bool {
      vector B(N, vector(M, false));
      REP(i, 0, N) REP(j, 0, M) B[i][j] = A[i][j] >= l;
      vector C(N, vector(M, false));
      REP(i, 0, N) {
        ll p = 0;
        while (true) {
          for (; p < M and not B[i][p]; p++);
          if (p == M) break;
          ll q = p;
          for (; q < M and B[i][q]; q++);
          for (; p + l <= q; p++) C[i][p] = true;
          p = q;
        }
      }
      REP(j, 0, M) {
        ll p = 0;
        while (true) {
          for (; p < N and not C[p][j]; p++);
          if (p == N) break;
          ll q = p;
          for (; q < N and C[q][j]; q++);
          if (p + l <= q) return true;
          p = q;
        }
      }
      return false;
    };
    ll ans = binsearch_i<ll>(check, 1, min(N, M) + 1);
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

