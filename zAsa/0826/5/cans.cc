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
  // @InpNbrList(N, M, nbr, dec=1) [MSqaYcGS]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [MSqaYcGS]

  vector ans(N, -1LL);
  vector<bool> A(N, false);
  set<ll> ss;
  ss.insert(0);
  ll top = -1;
  ll mex = 0;
  while (not ss.empty()) {
    ll x = *ss.begin();
    ss.erase(ss.begin());
    for (ll p : nbr[x]) if (not A[p]) ss.insert(p);
    A[x] = true;
    top = max(top, x);
    while (mex < N and A[mex]) mex++;
    if (top < mex) ans[top] = ssize(ss);
  }
  REPOUT(i, 0, N, ans[i], "\n");

  return 0;
}

