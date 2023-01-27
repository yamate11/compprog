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

  optional<string> s9;
  if (s9) cout << "s9 yes"; else cout << "s9 no";
  cout << endl;
  s9 = "";
  if (s9) cout << "s9 yes"; else cout << "s9 no";
  cout << endl;
  if (*s9 == "") cout << "*s9 yes"; else cout << "*s9 no";
  cout << endl;
  return 0;
  

  string S; cin >> S;
  ll N = SIZE(S);
  ll A = stoll(S);
  ll K; cin >> K;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }

  ll big = 1e18;
  ll ans = big;
  REP(x, 2, 1<<10) {
    if (__builtin_popcountll(x) > K) continue;
    ll lo = -1, hi = -1;
    ll lo2 = -1;
    REP(i, 0, 10) {
      if (x >> i & 1) {
        if (lo < 0) lo = i;
        if (lo2 < 0 and i > 0) lo2 = i;
        hi = i;
      }
    }

    string sc1(N - 1, '0' + hi);
    ll down = stoll(sc1);
    string sc2 = string(1, '0' + lo2) + string(N, '0' + lo);
    ll up = stoll(sc2);
    
    auto func1 = [&](auto rF, ll i) -> optional<string> {
      if (i == N) return "";
      ll d = S[i] - '0';
      optional<string> ret;
      if (x >> d & 1) {
        auto sc3 = rF(rF, i + 1);
        if (sc3.has_value()) ret = string(1, S[i]) + *sc3;
      }
      if (not ret.has_value() and lo < d) {
        ll p = d - 1;
        while (not (x >> p & 1)) p--;
        ret = string(1, '0' + p) + string(N - i - 1, '0' + hi);
      }
      return ret;
    };

    auto func2 = [&](auto rF, ll i) -> optional<string> {
      if (i == N) return "";
      ll d = S[i] - '0';
      optional<string> ret;
      if (x >> d & 1) {
        auto sc3 = rF(rF, i + 1);
        if (sc3.has_value()) ret = string(1, S[i]) + *sc3;
      }
      if (not ret.has_value() and hi > d) {
        ll p = d + 1;
        while (not (x >> p & 1)) p++;
        ret = string(1, '0' + p) + string(N - i - 1, '0' + lo);
      }
      return ret;
    };


    auto t1 = func1(func1, 0);
    if (t1.has_value()) down = max(down, stoll(*t1));
    auto t2 = func2(func2, 0);
    if (t2.has_value()) up = min(up, stoll(*t2));
    ll vthis = min(A - down, up - A);
    ans = min(ans, vthis);
  }
  cout << ans << endl;
  return 0;
}

