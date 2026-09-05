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

  ll N, Q, T; cin >> N >> Q >> T;
  // @InpVec(N, A) [5IN6QbbZ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [5IN6QbbZ]
  vector<ll> B(N + 1);
  REP(i, 0, N) B[i + 1] = B[i] + A[i];
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r; l--;
    bool b = B[r] - B[l] > T;
    cout << (b ? "Yes\n" : "No\n");
  }

  return 0;
}

