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

  vector<ll> P{1, 5, 10, 50, 100, 500};
  vector<ll> A(6);
  REP(i, 0, 6) cin >> A[i];
  ll N; cin >> N;
  // @InpVec(N, X) [sZjLDTnb]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [sZjLDTnb]
  ranges::sort(X, greater<ll>());
  REP(i, 0, N) {
    ll x = X[i];
    REPrev(j, 5, 0) {
      ll a = x / P[j];
      ll b = min(a, A[j]);
      x -= b * P[j];
      A[j] -= b;
    }
    if (x != 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

