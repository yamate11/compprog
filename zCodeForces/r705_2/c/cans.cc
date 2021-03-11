#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:intDiv)
// --> f:intDiv
// ---- inserted function intDiv from util.cc
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

// ---- end intDiv
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> string {
    ll N, K; cin >> N >> K;
    string S; cin >> S;
    if (N % K != 0) return "-1";
    vector<ll> cnt(128);
    for (ll i = 0; i < N; i++) cnt[S[i]]++;
    ll blocks = 0;
    for (char c = 'a'; c <= 'z'; c++) blocks += divCeil(cnt[c], K);
    if (blocks * K == N) return S;

    auto use = [&](ll m, char d) -> bool {
      if (blocks * K < N || cnt[d] % K > 0) {
        S[m] = d;
        if (cnt[d] % K == 0) blocks++;
        cnt[d]++;
        return true;
      }else return false;
    };

    auto placable = [&](char c0, ll m) -> bool {
      for (char d = c0; d <= 'z'; d++) if (use(m, d)) return true;
      return false;
    };

    ll m = N - 1;
    for (; m >= 0; m--) {
      ll c = S[m];
      cnt[c]--;
      if (cnt[c] % K == 0) blocks--;
      if (blocks * K <= N && placable(c + 1, m)) break;
    }
    for (; m < N; m++) placable('a', m);
    return S;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

