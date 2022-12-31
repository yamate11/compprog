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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [ZP1LqrZB]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [ZP1LqrZB]
  // @InpVec(N, B) [W1T8bv4o]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [W1T8bv4o]
  // @InpVec(N, P, dec=1) [1Cs4N4aH]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [1Cs4N4aH]
  
  auto AI = vector<pll>();
  REP(i, 0, N) AI.emplace_back(A[i], i);
  sort(ALL(AI));
  vector<ll> revP(N);
  REP(i, 0, N) revP[P[i]] = i;
  vector<pll> ans;
  for (auto [a, i] : AI) {
    if (P[i] == i) continue;
    if (B[P[i]] >= a) {
      cout << -1 << endl;
      return 0;
    }
    ll j = revP[i];
    ans.emplace_back(i, j);
    ll x = P[i];
    P[j] = x;
    revP[x] = j;
  }
  cout << SIZE(ans) << "\n";
  for (auto [x, y] : ans) cout << x+1 << " " << y+1 << "\n";


  return 0;
}

