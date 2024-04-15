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

// @@ !! LIM(f:updMaxMin)

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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [BLFXqm4G]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [BLFXqm4G]

  vector tbl(N, vector(N + 1, -1LL));
  vector op(N, vector(N + 1, -1LL));
  auto f = [&](auto rF, ll a, ll b) -> ll {
    ll& r_tbl = tbl[a][b];
    ll& r_op = op[a][b];
    if (r_tbl < 0) {
      if (a + 1 == b and A[a] > 0) {
        r_tbl = A[a];
        r_op = -1;
      }else {
        r_tbl = (b - a) * (b - a);
        r_op = b;
        REP(c, a + 1, b) {
          ll v = rF(rF, a, c) + rF(rF, c, b);
          if (r_tbl < v) {
            r_tbl = v;
            r_op = c;
          }
        }
      }
    }
    return r_tbl;
  };
  ll v = f(f, 0, N);
  vector<pll> ans;
  auto update = [&](ll a, ll b) -> void {
    if (a + 1 == b and A[a] > 0) A[a] = 0;
    else {
      REP(i, a, b) A[a] = b - a;
    }
    ans.emplace_back(a, b);
  };
  auto h = [&](auto rH, ll a, ll b) -> void {
    if (a + 1 == b) {
      if (A[a] > 0) update(a, a + 1);
    }else {
      rH(rH, a + 1, b);
      update(a + 1, b);
      rH(rH, a, b - 1);
    }
  };
  auto g = [&](auto rG, ll a, ll b) -> void {
    ll c = op[a][b];
    if (c < 0) ;
    else if (c == b) {
      h(h, a, b);
      update(a, b);
    }else {
      rG(rG, a, c);
      rG(rG, c, b);
    }
  };
  g(g, 0, N);
  cout << v << " " << ssize(ans) << "\n";
  for (auto [a, b] : ans) cout << a + 1 << " " << b << "\n";

  return 0;
}

