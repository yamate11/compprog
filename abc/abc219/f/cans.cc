#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

int main(istream& cin, ostream& cout) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll sz = S.size();
  ll K; cin >> K;
  auto move = [&](char c, ll& x, ll& y) -> void {
    if (c == 'L') x--;
    else if (c == 'R') x++;
    else if (c == 'U') y--;
    else if (c == 'D') y++;
    else assert(0);
  };
  ll x = 0, y = 0;
  for (ll i = 0; i < sz; i++) move(S[i], x, y);
  ll x0 = x, y0 = y;
  if (x0 == 0 && y0 == 0) {
    map<ll, set<ll>> ms;
    ll cnt = 0;
    for (ll i = 0; i < sz; i++) {
      if (ms[x].find(y) == ms[x].end()) {
        ms[x].insert(y);
        cnt++;
      }
      move(S[i], x, y);
    }
    cout << cnt << endl;
    return 0;
  }
  ll g0 = gcd(abs(x0), abs(y0));
  using sta = pair<ll, ll>;
  map<ll, vector<sta>> mp;
  x = 0;
  y = 0;
  mp[0].emplace_back(0, 0);
  for (ll i = 0; i < sz; i++) {
    move(S[i], x, y);
    ll d = y0 * x - x0 * y;
    mp[d].emplace_back(x, y);
  }
  auto sfn = [&](sta& p1, sta& p2) -> bool {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    if (x0 > 0) return x1 < x2;
    else if (x0 < 0) return x1 > x2;
    else if (y0 > 0) return y1 < y2;
    else return y1 > y2;
  };
  ll cnt = 0;
  for (auto& [d, vec] : mp) {
    sort(vec.begin(), vec.end(), sfn);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    auto [p, q] = vec[0];
    vector<vector<sta>> ww(g0);
    ww[0].emplace_back(p, q);
    for (ll i = 1; i < (ll)vec.size(); i++) {
      auto [pp, qq] = vec[i];
      ll r = (x0 != 0) ?
        imod(pp - p, abs(x0)) / abs(x0 / g0) :
        imod(qq - q, abs(y0)) / abs(y0 / g0) ;
      ww[r].emplace_back(pp, qq);
    }
    for (ll r = 0; r < g0; r++) {
      DLOGK(d, r, ww[r]);
      ll vsz = ww[r].size();
      if (vsz == 0) continue;
      for (ll i = 0; i + 1 < vsz; i++) {
        auto [x1, y1] = ww[r][i];
        auto [x2, y2] = ww[r][i + 1];
        if (x0 == 0) cnt += min(K, abs((y2 - y1) / y0));
        else         cnt += min(K, abs((x2 - x1) / x0));
      }
      cnt += K;
    }
  }
  cout << cnt << endl;
  return 0;
}

