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
  sort(ALL(A), greater<ll>());
  ll ans = 0;
  ll j = 0;
  ll t = 1;
  REP2(i, 1, N) {
    ans += A[j];
    if (t == 1) {
      j++; t = 0;
    }else {
      t = 1;
    }
  }
  cout << ans << endl;

  return 0;
}

