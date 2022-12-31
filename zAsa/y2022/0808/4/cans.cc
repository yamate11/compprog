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
  ll tot = 0;
  vector<ll> A(N);
  REP(i, N) {
    ll a; cin >> a;
    A[i] = a;
    tot += a;
  }
  if (tot % N != 0) {
    cout << -1 << endl;
    return 0;
  }
  ll avg = tot / N;
  ll ans = 0;
  ll s = 0;
  while (s < N) {
    ll t = 0;
    ll k = 0;
    while (true) {
      assert(s + k < N);
      t += A[s + k];
      if (t == avg * (k + 1)) break;
      k++;
      ans++;
    }
    s += k + 1;
  }
  cout << ans << endl;

  return 0;
}

