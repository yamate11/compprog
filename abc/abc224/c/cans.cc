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
  vector<ll> X(N), Y(N);
  REP(i, N) cin >> X[i] >> Y[i];
  ll cnt = 0;
  REP(i, N) REP2(j, i+1, N) REP2(k, j+1, N) {
    ll p1 = X[j] - X[i];
    ll q1 = Y[j] - Y[i];
    ll p2 = X[k] - X[i];
    ll q2 = Y[k] - Y[i];
    ll v = p1 * q2 - q1 * p2;
    if (v != 0) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

