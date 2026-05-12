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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, S, T; cin >> N >> M >> S >> T; S--; T--;
  vector<vector<ll>> A(M);
  vector<vector<ll>> B(N);
  REP(i, 0, M) {
    ll k; cin >> k;
    REP(j, 0, k) {
      ll a; cin >> a; a--;
      A[i].push_back(a);
      B[a].push_back(i);
    }
  }
  const ll big = 1e18;
  vector dist(2, vector<ll>());
  dist[0] = vector<ll>(M, big);
  dist[1] = vector<ll>(N, big);
  queue<pll> que;
  que.emplace(1, S);
  dist[1][S] = 0;
  while (not que.empty()) {
    auto [tp, idx] = que.front(); que.pop();
    if (tp == 0) {
      for (ll a : A[idx]) {
        if (dist[1][a] == big) {
          dist[1][a] = dist[tp][idx] + 1;
          que.emplace(1, a);
        }
      }
    }else {
      for (ll i : B[idx]) {
        if (dist[0][i] == big) {
          dist[0][i] = dist[tp][idx] + 1;
          que.emplace(0, i);
        }
      }
    }
  }
  ll ans = dist[1][T];
  if (ans == big) ans = -1;
  else ans = ans / 2;
  cout << ans << endl;

  return 0;
}

