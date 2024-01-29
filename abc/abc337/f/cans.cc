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

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(N, CC, dec=1) [JDYURLVf]
  auto CC = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; CC[i] = v; }
  // @End [JDYURLVf]
  
  vector C(2*N, 0LL);
  REP(i, 0, N) C[i] = C[N + i] = CC[i];

  vector ccnt(N, 0LL);
  REP(i, 0, N) ccnt[C[i]]++;

  map<ll, ll> on_map;
  ll m = 0;
  ll p = -1;
  REP(i, 0, N) {
    ll c = C[i];
    ll v = on_map[c];
    if (v % K == 0) {
      if (m == M) {
        p = i;
        break;
      }else {
        m++;
      }
    }
    on_map[c]++;
  }

  if (p < 0) {
    REPOUT(i, 0, N, N, "\n");
    return 0;
  }

  ll ans = 0;
  for (auto [c, v] : on_map) {
    ll t = divCeil(v, K) * K;
    ans += min(t, ccnt[c]);
  }

  REP(r, 0, N) {

    cout << ans << "\n";
    
    ll c = C[r];
    ll v = --on_map[c];
    if (v % K == 0) {

      ans -= min(ccnt[c], v + K) - v;

      ll cp = C[p];
      ll vvv = ++on_map[cp];
      ll ttt = divCeil(vvv, K) * K;
      ans += min(ttt, ccnt[cp]) - (vvv - 1);

      while (true) {
        p++;
        cp = C[p];
        ll vp = on_map[cp];
        if (vp % K != 0) {
          on_map[cp]++;
        }else {
          break;
        }
      }
    }
  }


  return 0;
}

