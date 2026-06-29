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

  ll N, M; cin >> N >> M;
  // @InpVec(N, B) [SttHOExy]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [SttHOExy]
  // @InpNbrList(N, M, fwd, dir=True, dec=1) [Kmzm6J48]
  auto fwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
  }
  // @End [Kmzm6J48]
  auto comp = [&](ll p, ll q) -> ll { return B[p] < B[q]; };
  REP(i, 0, N) {
    ranges::sort(fwd[i], comp);
  }
  vector<ll> cities(N);
  REP(i, 0, N) cities[i] = i;
  ranges::sort(cities, comp);
  vector<bool> done(N, false);
  vector<ll> ans;
  auto op = [&](ll nd) -> void {
    auto make_done = [&](ll z) -> void {
      done[z] = true;
      ans.push_back(z);
    };
    auto get_undone = [&](ll z) -> ll {
      while (not fwd[z].empty()) {
        ll p = fwd[z].back(); fwd[z].pop_back();
        if (not done[p]) return p;
      }
      return -1;
    };

    ll x = nd;
    make_done(x);
    while (true) {
      ll y = get_undone(x);
      if (y < 0) break;
      make_done(y);
      x = y;
    }
  };
  op(0);
  while (not cities.empty()) {
    ll i = cities.back(); cities.pop_back();
    if (not done[i]) op(i);
  }
  REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");
  
  return 0;
}

