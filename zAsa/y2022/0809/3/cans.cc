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

  ll m, n, N; cin >> m >> n >> N;
  ll cnt = 0;
  ll st = 0;
  while (N > 0) {
    cnt += N;
    ll x = (N + st) / m;
    ll y = (N + st) % m;
    st = y;
    N = n * x;
  }
  cout << cnt << endl;

  return 0;
}

