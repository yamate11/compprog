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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B; cin >> N >> A >> B;
  // @InpVec(N, V) [lqnqoR0C]
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; V[i] = v; }
  // @End [lqnqoR0C]

  sort(ALL(V), greater<ll>());
  double sum = 0; REP(i, 0, A) sum += V[i];
  cout << sum / A << endl;

  ll a = A - 1 , b = A;
  while (a - 1 >= 0 and V[a - 1] == V[A - 1]) a--;
  while (b < N and V[A - 1] == V[b]) b++;
  ll n = b - a;
  ll m = min(n, B - a);
  ll r = A - a;

  vector tbl(n + 1, 0LL);
  tbl[0] = 1;
  REP(i, 1, n + 1) tbl[i] = tbl[i - 1] * (n + 1 - i) / i;

  if (V[0] ![O= V[A - 1]) {
    cout << tbl[r] << endl;
  }else {
    ll ans = 0;
    REP(i, r, m + 1) ans += tbl[i];
    cout << ans << endl;
  }

  return 0;
}

