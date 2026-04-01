#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Y; cin >> N >> Y;
  vector<ll> kinds(N, 0LL);
  vector<ll> X(N);
  REP(i, 0, N) {
    string s; cin >> s;
    ll x; cin >> x;
    for (char c : s) kinds[i] |= (1LL << (c - 'a'));
    X[i] = x;
  }
  ll ans = 0;
  REP(x, 0, 1LL << N) {
    ll t = 0;
    ll y = 0;
    REP(i, 0, N) if (x >> i & 1) {
      t += X[i];
      y |= kinds[i];
    }
    if (t <= Y) ans = max(ans, (ll)popcount((u64)y));
  }
  cout << ans << endl;

  return 0;
}

