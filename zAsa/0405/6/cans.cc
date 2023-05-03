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

  ll S, T, M; cin >> S >> T >> M;
  // @InpNbrList(S + T, M, nbr, dec=1)

  // @InpMVec(M, ((U, dec=1), (V, dec=1))) [fAmOvAWD]
  auto U = vector(M, ll());
  auto V = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
  }
  // @End [fAmOvAWD]

  vector bwd(T, vector<ll>());
  REP(i, 0, M) bwd[V[i] - S].push_back(U[i]);
  vector fwd(S, vector<ll>());
  REP(i, 0, M) fwd[U[i]].push_back(V[i] - S);
  REP(i, 0, T) {
    vector<ll> vec(T, -1LL);
    for (ll j : bwd[i]) {
      for (ll k : fwd[j]) {
        if (k == i) continue;
        if (vec[k] >= 0) {
          cout << S + i + 1 << " " << j + 1 << " " << S + k + 1 << " " << vec[k] + 1 << endl;
          return 0;
        }else {
          vec[k] = j;
        }
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

