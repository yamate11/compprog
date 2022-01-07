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

  ll N, M; cin >> N >> M;
  map<ll, vector<ll>> mp3;
  vector<ll> fwd(N, -1);
  set<ll> ticks;
  REP(i, N) {
    ll a; cin >> a;
    ll c = imod(-a, M);
    fwd[i] = c;
    ticks.insert(c);
  }
  REP(i, N) {
    ll b; cin >> b;
    mp3[b].push_back(i);
    ticks.insert(b);
  }
  map<ll, ll> mp2;
  ll a_prev = -1;
  for (ll a : ticks) {
    if (a_prev >= 0) mp2[a_prev] = a - a_prev;
    a_prev = a;
  }
  mp2[a_prev] = *ticks.begin() + M - a_prev;
  using sta = tuple<ll, bool, ll>;
  vector<ll> dist1(N, LLONG_MAX);
  map<ll, ll> dist2;
  for (ll a: ticks) dist2[a] = LLONG_MAX;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  pque.emplace(0, false, 0);

  auto get_dist = [&](bool b, ll x) -> ll {
    if (b) return dist2[x];
    else   return dist1[x];
  };
  auto set_dist = [&](bool b, ll x, ll d) -> void {
    if (b) dist2[x] = d;
    else   dist1[x] = d;
  };
  using stb = tuple<ll, bool, ll>;
  auto nbr = [&](bool b, ll x) -> vector<stb> {
    if (b) {
      vector<stb> ret;
      for (ll y : mp3[x]) ret.emplace_back(0, false, y);
      ret.emplace_back(mp2[x], true, (x + mp2[x]) % M);
      return ret;
    }else {
      vector<stb> ret;
      ret.emplace_back(0, true, fwd[x]);
      return ret;
    }
  };

  set_dist(false, 0, 0);
  while (not pque.empty()) {
    auto [d, b, x] = pque.top(); pque.pop();
    if (get_dist(b, x) < d) continue;
    if (b == false and x == N - 1) {
      cout << d << endl;
      return 0;
    }
    for (auto [d1, b1, x1] : nbr(b, x)) {
      if (d + d1 >= get_dist(b1, x1)) continue;
      set_dist(b1, x1, d + d1);
      pque.emplace(d + d1, b1, x1);
    }
  }
  assert(0);

  return 0;
}

