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
  // @InpVec(N, R) [tS0zavvd]
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; R[i] = v; }
  // @End [tS0zavvd]
  // @InpVec(N, C) [nZp2FxeX]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [nZp2FxeX]

  ll Q; cin >> Q;
  REP(q, 0, Q) {
    ll r, c; cin >> r >> c; r--; c--;
    if (C[c] + R[r] >= N + 1) cout << '#';
    else cout << '.';
  }
  cout << endl;

  return 0;
}

