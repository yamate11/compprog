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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

pair<vector<int>, int> func_loop_detect(int n, int init, auto f) {
  vector<int> ret;
  vector<int> record(n, -1);
  int a = init;
  for (int i = 0; true; i++) {
    if (record[a] >= 0) return {move(ret), record[a]};
    ret.push_back(a);
    record[a] = i;
    a = f(a);
  }
}

template<bool directed>
pair<vector<int>, int> graph_loop_detect(int n, int init, const auto& fwd) {
  struct myexc : exception {};
  vector<int> ret;
  vector<int> record(n, -1);
  vector<bool> visited(n);
  int ret_idx = -1;
  auto dfs = [&](auto rF, int nd, int idx, int pt) -> void {
    if (record[nd] >= 0) {
      ret_idx = record[nd];
      throw myexc();
    }
    if (visited[nd]) return;
    visited[nd] = true;
    ret.push_back(nd);
    record[nd] = idx;
    for (int cld : fwd[nd]) {
      if constexpr (not directed) {
        if (cld == pt) continue;
      }
      rF(rF, cld, idx + 1, nd);
    }
    record[nd] = -1;
    ret.pop_back();
  };
  try {
    dfs(dfs, init, 0, -1);
    return {vector<int>(), -1};
  }catch (myexc& e) {
    return {move(ret), ret_idx};
  }
}

pair<vector<int>, int> directed_loop_detect(int n, int init, const auto& fwd) {
  return graph_loop_detect<true>(n, init, fwd);
}
pair<vector<int>, int> undirected_loop_detect(int n, int init, const auto& nbr) {
  return graph_loop_detect<false>(n, init, nbr);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X, M; cin >> N >> X >> M;
  auto [vec, ent] = func_loop_detect(M, X, [&](ll a) -> ll { return a * a % M; });
  ll len = SIZE(vec) - ent;
  vector<ll> S(ent + len + 1);
  REP(i, 0, ent + len) S[i + 1] = S[i] + vec[i];
  ll ans = -1;
  if (N <= ent) ans = S[N];
  else {
    ll r = (N - ent) % len;
    ll p = (N - ent) / len;
    ans = p * (S[ent + len] - S[ent]) + S[ent + r];
  }
  cout << ans << endl;
  return 0;
}

