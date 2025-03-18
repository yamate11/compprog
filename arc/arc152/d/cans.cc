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

  ll N, K; cin >> N >> K;

  auto report = [&](ll a, ll b) -> void {
    cout << (a % N) << " " << (b % N) << "\n";
  };

  if (N % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  ll M = (N - 1) / 2;
  cout << M << endl;
  ll g = gcd(N, K);
  if (g == 1) {
    REP(i, 0, M) {
      ll a = (2 * i + 0) * K;
      ll b = (2 * i + 1) * K;
      report(a, b);
    }
    return 0;
  }
  ll t = N / g;
  report(0, 1);
  report(1, K);
  REP(i, 0, (t - 3) / 2) {
    ll a = (3 + 2 * i + 0) * K;
    report(0, a);
  }
  REP(r, 1, g) REP(i, 0, (t - 1) / 2) {
    if (r == 1 and i == 0) continue;
    ll a = r + 2 * i * K;
    report(0, a);
  }
  REP(s, 0, (g - 1) / 2) {
    ll r = 1 + 2 * s;
    ll a = (r + 1) + (t - 2) * K;
    ll b = r + (t - 1) * K;
    report(a, b);
  }
  return 0;
}

