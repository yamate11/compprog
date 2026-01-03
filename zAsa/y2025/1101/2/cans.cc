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

  ll N; cin >> N;
  // @InpVec(N, R, dec=1) [pArbK5zd]
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; R[i] = v; }
  // @End [pArbK5zd]
  // @InpVec(N, C, dec=1) [lLd7FZNV]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; C[i] = v; }
  // @End [lLd7FZNV]

  vector<ll> revR(N), revC(N);
  REP(i, 0, N) {
    revR[R[i]] = i;
    revC[C[i]] = i;
  }
  revR = R;
  revC = C;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll r, c; cin >> r >> c; r--; c--;
    if (revR[r] + revC[c] >= N - 1) cout << "#";
    else cout << ".";
  }
  cout << "\n";

  return 0;
}

