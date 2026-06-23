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

  ll N, Q, R; cin >> N >> Q >> R;
  // @InpNbrList(N, N - 1, nbr, dec=1) [TO7Ub0l9]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [TO7Ub0l9]
  vector<ll> S(N, 0LL);
  vector<ll> D1(N, 0LL);
  vector<ll> D2(N, 0LL);
  auto f = [&](auto rF, ll nd, ll pt, ll r) -> ll {
    ll d = 0;
    if (S[nd] == 0) d++;
    else if (S[nd] == 1) d--;
    S[nd]++;
    /*
    if (r > 0) {
      for (ll peer : nbr[nd]) {
        if (peer != pt) d += rF(rF, peer, nd, r - 1);
      }
    }
    */
    if (r > 0 and (r > D2[nd])) {
      for (ll peer : nbr[nd]) {
        if (peer != pt) d += rF(rF, peer, nd, r - 1);
      }
      if (r > D1[nd]) {
        D2[nd] = D1[nd];
        D1[nd] = r;
      }else {
        D2[nd] = r;
      }
    }
    return d;
  };
  ll v = 0;
  REP(q, 0, Q) {
    ll c; cin >> c; c--;
    ll d = f(f, c, -1, R);
    v += d;
    cout << v << "\n";
  }

  return 0;
}

