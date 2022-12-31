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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X, A, D, N; cin >> X >> A >> D >> N;
  ll E = A + D * (N - 1);
  ll v = min(A, E);
  ll w = max(A, E);
  ll ans = -1;
  if (X <= v) ans = v - X;
  else if (w <= X) ans = X - w;
  else {
    ll r = (X - v) % abs(D);
    ans = min(r, abs(D) - r);
  }
  cout << ans << endl;

  return 0;
}

