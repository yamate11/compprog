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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(mapget)

// ---- inserted library file mapget.cc

template<typename MP>
typename MP::mapped_type mapget(MP& mp,
            const typename MP::key_type& a,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  auto it = mp.find(a);
  return it == mp.end() ? def : it->second;
}


template<typename MP>
void mapset(MP& mp,
            const typename MP::key_type& a,
            typename MP::mapped_type&& val,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  if (val == def) mp.erase(a);
  else mp[a] = forward<typename MP::mapped_type>(val);
}

// ---- end mapget.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N; cin >> H >> W >> N;
  ll sx, sy; cin >> sx >> sy;
  ll gx, gy; cin >> gx >> gy;
  map<ll, vector<ll>> mpx, mpy;
  REP(i, 0, N) {
    ll x, y; cin >> x >> y;
    mpx[x].push_back(y);
    mpy[y].push_back(x);
  }
  for (auto& [x, ys] : mpx) sort(ALL(ys));
  for (auto& [y, xs] : mpy) sort(ALL(xs));
  queue<pll> que;
  map<pll, ll> dist;
  dist[pll(sx, sy)] = 0;
  que.emplace(sx, sy);
  ll big = 1e18;

  auto func = [&](ll t, auto& mp) -> pll {
    auto it = mp.find(t);
    if (it == mp.end()) return {big, big};
    auto vec = it->second;
    ll i = lower_bound(ALL(vec), t) - vec.begin();
    ll b = i == SIZE(vec) ? big : vec[i] - 1;
    ll a = i == 0 ? big : vec[i - 1] + 1;
    return {a, b};
  };


  while (not que.empty()) {
    auto [x, y] = que.front(); que.pop();
    ll a, b; 
    tie(a, b) = func(x, mpx);
    for (ll c : {a, b}) {
      if (c != big and mapget(dist, pll(x, c), big) == big) {
        dist[pll(x, c)] = dist[pll(x, y)] + 1;
        que.emplace(x, c);
        if (x == gx and c == gy) {
          cout << dist[pll(gx, gy)] << endl;
          return 0;
        }
      }
    }
    tie(a, b) = func(y, mpy);
    for (ll c : {a, b}) {
      if (c != big and mapget(dist, pll(c, y), big) == big) {
        dist[pll(c, y)] = dist[pll(x, y)] + 1;
        que.emplace(c, y);
        if (c == gx and y == gy) {
          cout << dist[pll(gx, gy)] << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

