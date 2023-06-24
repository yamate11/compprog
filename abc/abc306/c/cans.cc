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
  // @InpVec(3*N, A, dec=1) [VP5eWHr8]
  auto A = vector(3*N, ll());
  for (int i = 0; i < 3*N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [VP5eWHr8]
  vector pos(N, vector<ll>());
  REP(i, 0, 3*N) {
    pos[A[i]].push_back(i);
  }
  REP(i, 0, 3*N) sort(ALL(pos[A[i]]));
  vector<ll> ord(N); REP(i, 0, N) ord[i] = i;
  sort(ALL(ord),
       [&](ll a, ll b) -> bool {
         return pos[a][1] < pos[b][1];
       });
  REPOUT(i, 0, N, ord[i] + 1, " ");

  return 0;
}

