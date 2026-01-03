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
  // @InpNbrList(N, M, nbr, dec=1) [36jxqYPh]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [36jxqYPh]

  vector<bool> used(N, false);
  ll z0 = nbr[0][0];
  used[0] = true;
  used[z0] = true;

  auto f = [&](ll x0) -> vector<ll> {
    vector<ll> ret{x0};
    ll x = x0;
    while (true) {
      auto choose = [&]() -> ll {
        for (ll y : nbr[x]) {
          if (not used[y]) {
            used[y] = true;
            return y;
          }
        }
        return -1;
      };
      ll y = choose();
      if (y < 0) return ret;
      ret.push_back(y);
      x = y;
    }
  };


  auto vec0 = f(0);
  auto vec1 = f(z0);
  cout << ssize(vec0) + ssize(vec1) << endl;
  for (ll i = ssize(vec0) - 1; i >= 0; i--) cout << vec0[i] + 1 << " ";
  REPOUT(i, 0, ssize(vec1), vec1[i] + 1, " ");


  return 0;
}

