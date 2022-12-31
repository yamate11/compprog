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

  ll N; cin >> N;
  vector<ll> C(N);
  ll sumB = 0;
  REP(i, 0, N) {
    ll a, b; cin >> b >> a;
    sumB += b;
    C[i] = a + 2 * b;
  }
  sort(ALL(C), greater<ll>());
  ll t = 0;
  REP(i, 0, N + 1) {
    if (t > sumB) {
      cout << i << endl;
      return 0;
    }
    t += C[i];
  }
  assert(0);

  return 0;
}

