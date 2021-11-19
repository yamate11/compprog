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
  auto f = [&](ll n) -> ll {
    ll m = 10;
    while (true) {
      ll t = n & ((1LL << m) - 1);
      if (t < N) return t;
      m--;
    }
  };
  REP(i, N) {
    ll x = f(2 * i);
    ll y = f(2 * i + 1);
    cout << x + 1 << " " << y + 1 << "\n";
  }

  return 0;
}

