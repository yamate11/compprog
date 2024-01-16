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

  auto f = [&](ll x) -> string {
    auto sub = [&](ll y) -> string {
      string t = "0" + to_string(y);
      ll l = SIZE(t);
      return t.substr(l - 2, 2);
    };
    x *= 5;
    ll a = x / 60;
    ll b = x % 60;
    return sub(a) + sub(b);
  };

  vector<bool> vec(12*24 + 2);
  ll N; cin >> N;
  REP(i, 0, N) {
    string s; cin >> s;
    ll a = stoll(s.substr(0, 2)) * 60 + stoll(s.substr(2, 2));
    ll b = stoll(s.substr(5, 2)) * 60 + stoll(s.substr(7, 2));
    a = divFloor(a, 5);
    b = divCeil(b, 5);
    REP(j, a, b) vec[1 + j] = true;
  }
  ll i = 0;
  for (; i < 12*24 + 1; i++) {
    if (not vec[i] and vec[i + 1]) {
      cout << f(i) << "-";
    }
    if (vec[i] and not vec[i + 1]) {
      cout << f(i) << "\n";
    }
  }

  return 0;
}

