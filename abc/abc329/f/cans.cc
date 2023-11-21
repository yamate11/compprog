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
  // @InpVec(N, C, dec=1) [ZfjCpFP1]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; C[i] = v; }
  // @End [ZfjCpFP1]

  vector<set<ll>> X(N);
  REP(i, 0, N) X[i].insert(C[i]);
  vector F(N, 0LL);
  REP(i, 0, N) F[i] = i;
  REP(_q, 0, Q) {
    ll a, b; cin >> a >> b; a--; b--;
    ll ta = F[a];
    ll tb = F[b];
    if (SIZE(X[ta]) <= SIZE(X[tb])) {
      for (ll i : X[ta]) X[tb].insert(i);
      X[ta] = set<ll>();
    }else {
      for (ll i : X[tb]) X[ta].insert(i);
      X[tb] = set<ll>();
      F[b] = ta;
      F[a] = tb;
    }
    tb = F[b];
    cout << SIZE(X[tb]) << "\n";
  }

  return 0;
}

