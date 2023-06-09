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

  ll N; cin >> N;
  // @InpMVec(N, ((A, dec=1),(B, dec=1))) [xprFX3zB]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [xprFX3zB]
  // @InpNbrList(N, N-1, nbr, dec=1) [hg2bbZyq]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N-1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [hg2bbZyq]
  vector ufp(N, 0LL);
  REP(i, 0, N) ufp[i] = i;
  vector hasLoop(N, false);
  vector ufsz(N, 0LL);
  REP(i, 0, N) ufsz[i] = 1;
  auto leader = [&](ll x) -> ll {
    while (ufp[x] != x) x = ufp[x];
    return x;
  };

  vector<ll> ans(N);
  ll cur = 0;
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    ll a = leader(A[nd]);
    ll b = leader(B[nd]);
    ll oldCur = cur;
    bool oldHasLoopA = hasLoop[a];
    bool oldHasLoopB = hasLoop[b];
    ll oldSizeA = ufsz[a];
    ll oldSizeB = ufsz[b];
    if (a == b) {
      if (hasLoop[a]) {
        // do nothing
      }else {
        hasLoop[a] = true;
        cur++;
      }
    }else {
      ll newLeader;
      if (ufsz[a] > ufsz[b]) newLeader = a;
      else newLeader = b;
      ufp[a] = newLeader;
      ufp[b] = newLeader;
      ufsz[newLeader] = ufsz[a] + ufsz[b];
      if (not (hasLoop[a] and hasLoop[b])) cur++;
      hasLoop[newLeader] = hasLoop[a] or hasLoop[b];
    }
    ans[nd] = cur;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
    cur = oldCur;
    ufp[a] = a;
    ufp[b] = b;
    hasLoop[a] = oldHasLoopA;
    hasLoop[b] = oldHasLoopB;
    ufsz[a] = oldSizeA;
    ufsz[b] = oldSizeB;
  };
  dfs(dfs, 0, -1);
  REPOUT(i, 1, N, ans[i], " ");

  return 0;
}

