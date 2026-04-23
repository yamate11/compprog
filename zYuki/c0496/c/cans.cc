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

// @@ !! LIM(binsearch)

// ---- inserted library file binsearch.cc

template <typename T>
requires integral<T>
T binsearch(auto check, T yes, T no) {
  while (abs(no - yes) > 1) {
    T mid = yes + (no - yes) / 2;  // avoiding unnecessary overflow
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template <typename T>
requires floating_point<T>
T binsearch(auto check, T yes, T no, T err, const bool abs_only = false) {
  T rep_in_t = ceil(log(abs(yes - no) / err) / log(2.0));
  constexpr int lim = INT_MAX - 10;
  int rep = rep_in_t > (T)lim ? lim : llround(rep_in_t) + 1;
  for (int r = 0; r < rep; r++) {
    T mid = (yes + no) / 2.0;
    if (not abs_only) {
      if (abs(yes - mid) < err * min(abs(mid), abs(yes))) return mid;
    }
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1, read=H) [W60DNwf4]
  struct nbr_t {
    int nd;
    ll H;
    nbr_t(int nd_ = int(), ll H_ = ll()) : nd(nd_), H(H_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll H; cin >> H;
    nbr[u].emplace_back(v, H);
    nbr[v].emplace_back(u, H);
  }
  // @End [W60DNwf4]

  ll big = 1e18;
  auto check = [&](ll x) -> bool {
    vector dist(N, big);
    queue<ll> que;
    dist[0] = 0;
    que.push(0);
    while (not que.empty()) {
      auto nd = que.front(); que.pop();
      if (nd == N - 1) return true;
      for (auto [peer, h] : nbr[nd]) {
        if (x <= h) {
          if (dist[peer] == big) {
            dist[peer] = dist[nd] + 1;
            que.push(peer);
          }
        }
      }
    }
    return false;
  };

  ll x = binsearch<ll>(check, 0, (ll)1e9 + 10);
  if (x == 0) {
    cout << "NaN\n";
  }else {
    cout << x << endl;
  }

  return 0;
}

