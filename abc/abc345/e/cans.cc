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

  ll N, M, K; cin >> N >> M >> K;
  // @InpMVec(M, ((U, dec=1), (V, dec=1))) [shGBSE7u]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
  }
  // @End [shGBSE7u]

  if (K % 2 == 1) {
    cout << "No\n";
    return 0;
  }

  /*
  unordered_map<ll, unordered_map<ll, ll>> mp;
  REP(i, 0, N) REP(j, 0, N) mp[U[i]][V[i]] = i;
  */
  
  vector<vector<pll>> nbr(N);
  REP(i, 0, N) {
    nbr[U[i]].emplace_back(V[i], i);
    nbr[V[i]].emplace_back(U[i], i);
  }

  vector<ll> ans;
  vector<bool> visited(N);
  
  auto func = [&](auto rF, ll nd, ll rem) -> pll {
    bool status = false;
    ll myrem = rem;
    visited[nd] = true;
    for (auto [peer, idx] : nbr[nd]) {
      if (visited[peer]) continue;
      auto [crem, cv] = rF(rF, peer, rem);
      if (crem == 0) return pll(0, false);
      myrem = crem;
      if (not cv) {
        ans.push_back(idx);
        if (not status) myrem -= 2;
        status = not status;
      }
    }
    return pll(myrem, status);
  };

  ll rem = K;
  REP(nd, 0, N) {
    if (not visited[nd]) {
      auto [w, v] = func(func, nd, rem);
      rem = w;
      if (rem == 0) {
        cout << "Yes\n";
        cout << ssize(ans) << "\n";
        REPOUT(i, 0, ssize(ans), ans[i], " ");
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}

