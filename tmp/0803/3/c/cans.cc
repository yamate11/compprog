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

  ll N, T; cin >> N >> T;
  ll s = 0;
  vector<ll> D(N);
  REP(i, N) {
    ll a, b; cin >> a >> b;
    s += a;
    D[i] = a - b;
  }
  sort(ALL(D), greater<ll>());
  ll c = 0;
  ll g = 0;
  REP(i, N) {
    if (s - g <= T) break;
    g += D[i];
    c++;
  }
  if (s - g > T) c = -1;
  cout << c << endl;

  return 0;
}

