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

int main() {
  const ll big = 1e18;

  string first, last; cin >> first >> last;
  ll N; cin >> N;
  vector<string> S(N + 2); REP(i, N) cin >> S[i];
  if (first == last) {
    cout << 0 << endl << first << endl << last << endl;
    return 0;
  }
  S[N] = first;
  S[N + 1] = last;
  vector nbr(N + 2, vector<ll>());
  REP(i, N + 2) REP(j, i + 1, N + 2) {
    ll c = 0;
    REP(k, SIZE(S[i])) if (S[i][k] != S[j][k]) c++;
    if (c == 1) {
      nbr[i].push_back(j);
      nbr[j].push_back(i);
    }
  }
  vector dist(N + 2, big);
  vector prev(N + 2, -1LL);
  queue<ll> que;
  dist[N] = 0;
  que.emplace(N);
  while (not que.empty()) {
    auto nd = que.front(); que.pop();
    for (ll c : nbr[nd]) {
      if (dist[c] < big) continue;
      dist[c] = dist[nd] + 1;
      prev[c] = nd;
      que.emplace(c);
    }
  }
  if (dist[N + 1] == big) {
    cout << -1 << endl;
    return 0;
  }
  vector<ll> ans;
  ll idx = N + 1;
  while (idx >= 0) {
    ans.push_back(idx);
    idx = prev[idx];
  }
  reverse(ALL(ans));
  cout << dist[N + 1] - 1 << endl;
  for (ll i : ans) cout << S[i] << "\n";
  return 0;
}

