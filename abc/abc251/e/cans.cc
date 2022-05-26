#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  const ll big = 1e18;
  ll ans = big;
  ll p = A[0];
  ll q = big;
  REP2(i, 1, N - 1) {
    ll oldp = p;
    ll oldq = q;
    p = q = big;
    p = min(oldp + A[i], oldq + A[i]);
    q = oldp;
  }
  ans = min(ans, p);
  ans = min(ans, q + A[N-1]);
  
  p = big;
  q = A[N-1];
  REP2(i, 1, N - 1) {
    ll oldp = p;
    ll oldq = q;
    p = q = big;
    p = min(oldp + A[i], oldq + A[i]);
    q = oldp;
  }
  ans = min(ans, p);
  ans = min(ans, q);
  cout << ans << endl;

  return 0;

}

