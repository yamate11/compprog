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

  ll n; cin >> n;
  // @InpVec(n, R) [QnSw1s5l]
  auto R = vector(n, ll());
  for (int i = 0; i < n; i++) { ll v; cin >> v; R[i] = v; }
  // @End [QnSw1s5l]
  // @InpVec(n, C) [P5LMtXg7]
  auto C = vector(n, ll());
  for (int i = 0; i < n; i++) { ll v; cin >> v; C[i] = v; }
  // @End [P5LMtXg7]
  ll q; cin >> q;
  REP(_q, 0, q) {
    ll r, c; cin >> r >> c; r--; c--;
    if (R[r] + C[c] >= n + 1) cout << '#';
    else cout << '.';
  }
  cout << "\n";

  return 0;
}

