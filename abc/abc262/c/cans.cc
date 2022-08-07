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
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
    A[i]--;
  }
  ll cnt1 = 0;
  ll cnt2 = 0;
  REP(i, N) {
    if (A[i] == i) cnt1++;
    if (i < A[i] and A[A[i]] == i) cnt2++;
  }
  ll ans = cnt1 * (cnt1 - 1) / 2 + cnt2;
  cout << ans << endl;

  return 0;
}

