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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N + 1), B(N + 1), C(N + 1);
  REP(i, 1, N + 1) cin >> A[i];
  REP(i, 1, N + 1) cin >> B[i];
  REP(i, 1, N + 1) cin >> C[i];
  map<ll, ll> mp;
  REP(i, 1, N + 1) mp[A[i]]++;
  ll ans = 0;
  REP(i, 1, N + 1) ans += mp[B[C[i]]];
  cout << ans << endl;

  return 0;
}

