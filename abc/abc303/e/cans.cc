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
  // @InpNbrList(N, N - 1, nbr, dec=1) [69bL3Zuh]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [69bL3Zuh]

  vector<ll> leaves;
  vector<bool> removed(N);
  REP(i, 0, N) {
    if (SIZE(nbr[i]) == 1) leaves.push_back(i);
  }
  vector<ll> ans;
  while (not leaves.empty()) {
    ll nd = leaves.back(); leaves.pop_back();
    if (removed[nd]) continue;
    ll c = -1;
    for (ll x : nbr[nd]) {
      if (not removed[x]) {
        c = x;
        break;
      }
    }
    assert(c >= 0);
    ans.push_back(SIZE(nbr[c]));
    removed[c] = true;
    for (ll x : nbr[c]) {
      removed[x] = true;
      if (SIZE(nbr[x]) == 2) {
        if (nbr[x][0] == c) leaves.push_back(nbr[x][1]);
        else leaves.push_back(nbr[x][0]);
      }
    }
  }
  sort(ALL(ans));
  REPOUT(i, 0, SIZE(ans), ans[i], " ");


  return 0;

}

