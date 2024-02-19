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
  // @InpVec(N, A) [5PmFp0yK]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [5PmFp0yK]
  ll Q; cin >> Q;
  vector rec(N + 1, vector<ll>());
  REP(i, 0, N) rec[A[i]].push_back(i);

  REP(_q, 0, Q) {
    ll l, r, x; cin >> l >> r >> x; l--;
    auto it1 = lower_bound(ALL(rec[x]), l);
    auto it2 = lower_bound(ALL(rec[x]), r);
    cout << it2 - it1 << "\n";
  }

  return 0;
}

