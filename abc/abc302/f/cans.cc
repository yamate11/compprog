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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> A(N);
  vector<vector<ll>> S(N);
  REP(i, 0, N) {
    cin >> A[i];
    S[i].resize(A[i]);
    REP(j, 0, A[i]) {
      cin >> S[i][j];
      S[i][j]--;
    }
  }
  vector<vector<pll>> fwd(N + M);
  REP(i, 0, N) {
    REP(j, 0, A[i]) {
      fwd[S[i][j]].emplace_back(M + i, 1);
      fwd[M + i].emplace_back(S[i][j], 0);
    }
  }
  ll big = 1e18;
  vector dist(N + M, big);
  deque<pll> deq;
  dist[0] = 0;
  deq.emplace_back(0, 0);
  while (not deq.empty()) {
    auto [d, nd] = deq.front(); deq.pop_front();
    if (d != dist[nd]) continue;
    for (auto [peer, len] : fwd[nd]) {
      ll newD = d + len;
      if (newD < dist[peer]) {
        dist[peer] = newD;
        if (len == 0) deq.emplace_front(newD, peer);
        else deq.emplace_back(newD, peer);
      }
    }
  }
  ll ans = dist[M - 1];
  if (ans == big) ans = -1;
  else ans--;
  cout << ans << endl;

  return 0;
}

