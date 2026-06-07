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
  ll S, T, P; cin >> S >> T >> P; S--; T--; P--;
  // @InpNbrList(N, M, nbr, dec=1, read=W) [lql8HM0B]
  struct nbr_t {
    int nd;
    ll W;
    ostream& operator<<(ostream& ostr) const {
      return ostr << "(" << nd << ", " << W << ")";
    }
    auto operator<=>(const nbr_t&) const = default;
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    nbr[u].emplace_back(v, W);
    nbr[v].emplace_back(u, W);
  }
  // @End [lql8HM0B]

  ll big = 1LL << 60;
  vector<ll> distP(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  distP[P] = 0;
  pque.emplace(0, P);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (distP[nd] == d) {
      for (auto [peer, len] : nbr[nd]) {
        ll new_d = d + len;
        if (new_d < distP[peer]) {
          distP[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }
    }
  }
  if (distP[S] == big) {
    assert(distP[T] == big);
    cout << "INF" << endl;
    return 0;
  }
  auto check = [&](ll th) -> bool {
    if (distP[S] < th or distP[T] < th) return false;
    vector dist(N, big);
    queue<ll> que;
    dist[S] = 0;
    que.push(S);
    while (not que.empty()) {
      auto nd = que.front(); que.pop();
      for (auto [peer, len] : nbr[nd]) {
        if (distP[peer] < th) continue;
        if (dist[peer] == big) {
          dist[peer] = dist[nd] + 1;
          que.push(peer);
        }
      }
    }
    return dist[T] < big;
  };
  ll th = binsearch<ll>(check, 0, big);
  cout << th << "\n";

  return 0;
}

