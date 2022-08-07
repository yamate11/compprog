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
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll sz = llround(ceil(sqrt(N)));
  vector<vector<ll>> div, divs;
  for (ll k = 0; k * sz < N; k++) {
    ll e = min(N, (k + 1) * sz);
    vector<ll> v;
    copy(A.begin() + k * sz, A.begin() + e, back_inserter(v));
    div.push_back(v);
    divs.push_back(move(v));
    sort(ALL(divs[k]));
  }
  ll Q; cin >> Q;
  REP(_q, Q) {
    ll L, R, D; cin >> L >> R >> D; R++;
    ll iL = divCeil(L, sz);
    ll iR = divFloor(R, sz);
    ll ans = 1e9;
    if (iL < iR) {
      REP2(i, iL, iR) {
        ll j = lower_bound(ALL(divs[i]), D) - divs[i].begin();
        ll hi, lo;
        if (j == SIZE(divs[i])) hi = 1e9;
        else hi = divs[i][j];
        if (j == 0) lo = -1e9;
        else lo = divs[i][j - 1];
        ans = min(ans, min(hi - D, D - lo));
      }
      REP2(i, L, iL * sz) ans = min(ans, abs(A[i] - D));
      REP2(i, iR * sz, R) ans = min(ans, abs(A[i] - D));
    }else {
      REP2(i, L, R) ans = min(ans, abs(A[i] - D));
    }
    cout << ans << "\n";
  }


  return 0;
}

