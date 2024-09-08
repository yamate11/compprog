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
  string S; cin >> S;
  vector<ll> tbl(N + 1, 0LL);
  tbl[0] = 1;
  REP(i, 0, N) {
    REP(d, 0, 10) {
      if (tbl[i] >> d & 1) {
        if (S[i] == '?') {
          REP(z, 0, 10) {
            ll e = (d + (i + 1) * z) % 10;
            tbl[i + 1] |= (1LL << e);
          }
        }else {
          ll e = (d + (i + 1) * (S[i] - '0')) % 10;
          tbl[i + 1] |= (1LL << e);
        }
      }
    }
  }
  if (not (tbl[N] >> 0 & 1)) {
    cout << "No\n";
  }else {
    cout << "Yes\n";
    ll y = 0;
    REPrev(i, N - 1, 0) {
      if (S[i] == '?') {
        REP(z, 0, 10) {
          ll e = imod(y - (i + 1) * z, 10);
          if (tbl[i] >> e & 1) {
            S[i] = (char)('0' + z);
            y = e;
            break;
          }
        }
        assert(S[i] != '?');
      }else {
        y = imod(y - (i + 1) * (S[i] - '0'), 10);
      }
    }
    cout << S << endl;
  }

  return 0;
}

