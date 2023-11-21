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

  ll N; cin >> N;
  // @InpVec(N, D) [yjLXiRQU]
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; D[i] = v; }
  // @End [yjLXiRQU]

  auto f = [&](ll i) -> ll {
    if (i < 10) return i;
    ll a = i % 10;
    ll b = i / 10;
    if (a == b) return a;
    return -1;
  };

  ll cnt = 0;
  REP(i, 1, N + 1) REP(j, 1, D[i - 1] + 1) {
    ll a = f(i);
    ll b = f(j);
    if (a >= 0 and a == b) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

