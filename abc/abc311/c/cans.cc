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

// @@ !! LIM(cycledetect)

// ---- inserted library file cycledetect.cc

pair<vector<int>, int> func_cycle_detect(int n, int init, auto f) {
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
pair<vector<int>, int> graph_cycle_detect(int n, int init, const auto& fwd) {
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

pair<vector<int>, int> directed_cycle_detect(int n, int init, const auto& fwd) {
  return graph_cycle_detect<true>(n, init, fwd);
}
pair<vector<int>, int> undirected_cycle_detect(int n, int init, const auto& nbr) {
  return graph_cycle_detect<false>(n, init, nbr);
}

// ---- end cycledetect.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A, dec=1) [wbZ3Z0KV]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [wbZ3Z0KV]

  auto f = [&](ll i) { return A[i]; };

  auto [vec, idx] = func_cycle_detect(N, 0, f);
  cout << SIZE(vec) - idx << endl;
  REPOUT(i, idx, SIZE(vec), vec[i] + 1, " ");

  return 0;
}

