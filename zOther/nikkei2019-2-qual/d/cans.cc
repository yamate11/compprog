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

// @@ !! LIM()

using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll big = 1e18;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> L(M), R(M), C(M);
  REP(i, M) {
    cin >> L[i] >> R[i] >> C[i]; L[i]--;
  }
  ll trht = 1 + 64 - __builtin_clzll(N - 1);
  ll trsz = 1LL << trht;
  auto node = [&](ll i) { return i; };
  auto itvl = [&](ll i) { return N + i; };
  auto tout = [&](ll i) { return N + M + i; };
  auto tin = [&](ll i) { return N + M + trsz + i; };
  ll T = N + M + 2 * trsz;

  auto get_tr_node = [&](ll l, ll r) -> vector<ll> {
    vector<ll> left;
    vector<ll> right;
    for (ll p = l + trsz/2, q = r + trsz/2 - 1; p <= q; p >>= 1, q >>= 1) {
      if (     p & 1 )  left.push_back(p++);
      if (not (q & 1)) right.push_back(q--);
    }
    left.insert(left.end(), right.rbegin(), right.rend());
    return left;
  };

  vector fwd(T, vpll());
  REP(i, N) {
    fwd[node(i)].emplace_back(tout(i + trsz/2), 0);
    fwd[tin(i + trsz/2)].emplace_back(node(i), 0);
  }
  REP(i, trsz/2) {
    REP(z, 2) {
      fwd[tin(i)].emplace_back(tin(2*i + z), 0);
      fwd[tout(2*i + z)].emplace_back(tout(i), 0);
    }
  }
  REP(i, M) {
    for (ll j : get_tr_node(L[i], R[i])) {
      fwd[itvl(i)].emplace_back(tin(j), C[i]);
      fwd[tout(j)].emplace_back(itvl(i), 0);
    }
  }

  vector dist(T, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[node(0)] = 0;
  pque.emplace(0, node(0));
  while (not pque.empty()) {
    auto [d, x] = pque.top(); pque.pop();
    if (dist[x] < d) continue;
    for (auto [y, ed] : fwd[x]) {
      if (d + ed >= dist[y]) continue;
      dist[y] = d + ed;
      pque.emplace(d + ed, y);
    }
  }
  auto alt = [&](ll x) { return x >= big ? -1 : x; };
  cout << alt(dist[node(N - 1)]) << endl;
  return 0;
}

