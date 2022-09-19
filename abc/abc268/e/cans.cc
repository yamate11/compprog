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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(f:intDiv)

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

  ll N; cin >> N;
  // @InpVec(N, P) [ZQWnLB64]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [ZQWnLB64]
  vector<ll> diff(N);
  vector<ll> chg(N);
  ll us = 0;
  REP(i, 0, N) {
    ll tus;
    if (i <= P[i]) {
      if (P[i] - i >= N + i - P[i]) {
        tus = N + i - P[i];
        diff[P[i]] = 1;
        chg[N /2 - tus] -= 1;
        chg[(N + 1) / 2 - tus] -= 1;
        chg[P[i] - i] += 2;
      } else {
        tus = P[i] - i;
        diff[P[i]] = -1;
        chg[tus] += 2;
        chg[tus + N / 2] -= 1;
        chg[tus + (N + 1) / 2] -= 1;
      }
    }else {
      if (i - P[i] > N + P[i] - i) {
        tus = N + P[i] - i;
        diff[P[i]] = -1;
        chg[N + P[i] - i] += 2;
        chg[N + P[i] - i + N / 2] -= 1;
        chg[N + P[i] - i + (N + 1) / 2] -= 1;
      }else {
        tus = i - P[i];
        diff[P[i]] = 1;
        chg[N / 2 - tus] -= 1;
        chg[(N + 1) / 2 - tus] -= 1;
        chg[N - tus] += 2;
      }
    }
    us += tus;
  }
  ll tdiff = 0;
  REP(i, 0, N) tdiff += diff[i];
  ll ans = us;
  REP(i, 0, N) {
    tdiff += chg[i];
    us += tdiff;
    ans = min(ans, us);
  }
  cout << ans << endl;
  

  return 0;
}

