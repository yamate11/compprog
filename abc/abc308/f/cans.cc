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

  ll N, M; cin >> N >> M;
  // @InpVec(N, P) [CCXs2DFK]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [CCXs2DFK]
  // @InpVec(M, L) [prNGFOH9]
  auto L = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; L[i] = v; }
  // @End [prNGFOH9]
  // @InpVec(M, D) [82ftrBSV]
  auto D = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; D[i] = v; }
  // @End [82ftrBSV]

  ll tot = 0; REP(i, 0, N) tot += P[i];
  ll disc = 0;

  multiset<ll> ss;
  REP(i, 0, N) ss.insert(P[i]);

  vector<ll> ord(M); REP(i, 0, M) ord[i] = i;
  sort(ALL(ord),
       [&](ll i, ll j) -> bool { return D[i] > D[j]; }
       );
  REP(_i, 0, M) {
    ll i = ord[_i];
    auto it = ss.lower_bound(L[i]);
    if (it != ss.end()) {
      disc += D[i];
      ss.erase(it);
    }
  }



  cout << tot - disc << endl;
  return 0;
}

