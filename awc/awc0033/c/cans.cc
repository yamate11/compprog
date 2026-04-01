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

  ll N, M, K, T; cin >> N >> M >> K >> T;
  // @InpVec(K, C, dec=1) [eHIbKqwm]
  auto C = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; C[i] = v; }
  // @End [eHIbKqwm]
  vector nbr(N, vector<ll>());
  vector nknow(N, 0LL);
  REP(i, 0, M) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  vector<bool> know(N, false);
  vector<ll> yet;
  REP(i, 0, K) {
    know[C[i]] = true;
    yet.push_back(C[i]);
  }
  while (not yet.empty()) {
    ll nd = yet.back(); yet.pop_back();
    for (ll p : nbr[nd]) {
      if (not know[p]) {
        if (++nknow[p] == T) {
          know[p] = true;
          yet.push_back(p);
        }
      }
    }
  }
  ll ans = 0;
  REP(i, 0, N) if (know[i]) ans++;
  cout << ans << endl;


  return 0;
}

