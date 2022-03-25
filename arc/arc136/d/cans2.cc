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
  vector v(10, vector(10, vector(10, vector(10, vector(10, vector(10, 0LL))))));
  REP(i, N) {
    ll a; cin >> a;
    A[i] = a;
    ll x0 = a % 10; a /= 10;
    ll x1 = a % 10; a /= 10;
    ll x2 = a % 10; a /= 10;
    ll x3 = a % 10; a /= 10;
    ll x4 = a % 10; a /= 10;
    ll x5 = a % 10; a /= 10;
    v[x0][x1][x2][x3][x4][x5]++;
  }
  REP(x0, 10) REP(x1, 10) REP(x2, 10) REP(x3, 10) REP(x4, 10) REP(x5, 9) v[x0][x1][x2][x3][x4][x5 + 1] += v[x0][x1][x2][x3][x4][x5];
  REP(x0, 10) REP(x1, 10) REP(x2, 10) REP(x3, 10) REP(x4, 9) REP(x5, 10) v[x0][x1][x2][x3][x4 + 1][x5] += v[x0][x1][x2][x3][x4][x5];
  REP(x0, 10) REP(x1, 10) REP(x2, 10) REP(x3, 9) REP(x4, 10) REP(x5, 10) v[x0][x1][x2][x3 + 1][x4][x5] += v[x0][x1][x2][x3][x4][x5];
  REP(x0, 10) REP(x1, 10) REP(x2, 9) REP(x3, 10) REP(x4, 10) REP(x5, 10) v[x0][x1][x2 + 1][x3][x4][x5] += v[x0][x1][x2][x3][x4][x5];
  REP(x0, 10) REP(x1, 9) REP(x2, 10) REP(x3, 10) REP(x4, 10) REP(x5, 10) v[x0][x1 + 1][x2][x3][x4][x5] += v[x0][x1][x2][x3][x4][x5];
  REP(x0, 9) REP(x1, 10) REP(x2, 10) REP(x3, 10) REP(x4, 10) REP(x5, 10) v[x0 + 1][x1][x2][x3][x4][x5] += v[x0][x1][x2][x3][x4][x5];
  ll ans = 0;
  ll self = 0;
  REP(i, N) {
    ll a = A[i];
    ll x0 = a % 10; a /= 10;
    ll x1 = a % 10; a /= 10;
    ll x2 = a % 10; a /= 10;
    ll x3 = a % 10; a /= 10;
    ll x4 = a % 10; a /= 10;
    ll x5 = a % 10; a /= 10;
    ans += v[9 - x0][9 - x1][9 - x2][9 - x3][9 - x4][9 - x5];
    if (x0 < 5 and x1 < 5 and x2 < 5 and x3 < 5 and x4 < 5 and x5 < 5) self++;
  }
  cout << (ans - self) / 2 << endl;

  return 0;
}

