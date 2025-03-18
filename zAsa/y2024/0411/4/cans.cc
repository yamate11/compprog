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

  string T; cin >> T;
  ll sz = ssize(T);
  ll N; cin >> N;
  vector S(N, vector<string>());
  REP(i, 0, N) {
    ll a; cin >> a;
    REP(j, 0, a) {
      string s; cin >> s;
      S[i].push_back(s);
    }
  }
  ll big = 1e18;
  vector tbl_init(sz + 1, big);
  auto tbl = tbl_init;
  tbl[0] = 0;
  REP(i, 0, N) {
    auto prev = tbl;
    REP(j, 0, sz + 1) {
      if (prev[j] < big) {
        for (string s : S[i]) {
          if (j + ssize(s) <= sz) {
            if (T.substr(j, ssize(s)) == s) updMin(tbl[j + ssize(s)], prev[j] + 1);
          }
        }
      }
    }
  }
  ll ans = tbl[sz];
  if (ans >= big) ans = -1;
  cout << ans << endl;

  return 0;
}

