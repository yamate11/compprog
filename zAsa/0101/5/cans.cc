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

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, C) [VEbxY2tC]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [VEbxY2tC]

  vector<set<ll>> V(N);
  REP(i, 0, N) V[i].insert(C[i]);
  REP(_q, 0, Q) {
    ll a, b; cin >> a >> b; a--; b--;
    if (SIZE(V[a]) > SIZE(V[b])) {
      for (ll x : V[b]) V[a].insert(x);
      V[b] = set<ll>();
      swap(V[a], V[b]);
    }else {
      for (ll x : V[a]) V[b].insert(x);
      V[a] = set<ll>();
    }
    cout << SIZE(V[b]) << "\n";
  }

  return 0;
}

