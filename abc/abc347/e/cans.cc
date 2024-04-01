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

  ll N, Q; cin >> N >> Q;
  // @InpVec(Q, X, dec=1) [1s3dQ9w5]
  auto X = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; v -= 1; X[i] = v; }
  // @End [1s3dQ9w5]
  
  set<ll> S;
  vector cnt(Q, 0LL);
  vector on(N, 0LL);
  vector son(N, vector<ll>());
  vector soff(N, vector<ll>());

  REP(i, 0, Q) {
    if (on[X[i]]) {
      cnt[i] = cnt[i - 1] - 1;
      on[X[i]] = false;
      soff[X[i]].push_back(i);
    }else {
      cnt[i] = i == 0 ? 1 : cnt[i - 1] + 1;
      on[X[i]] = true;
      son[X[i]].push_back(i);
    }
  }
  vector acc(Q + 1, 0LL);
  REP(i, 0, Q) acc[i + 1] = acc[i] + cnt[i];
  vector ans(N, 0LL);
  REP(i, 0, N) {
    REP(j, 0, ssize(son[i])) {
      if (j < ssize(soff[i])) {
        ans[i] += acc[soff[i][j]] - acc[son[i][j]];
      }else {
        ans[i] += acc[Q] - acc[son[i][j]];
      }
    }
  }
  REPOUT(i, 0, N, ans[i], " ");

  return 0;
}

