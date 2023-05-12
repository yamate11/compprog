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
  // @InpVec(N, A) [lc8qxHkp]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [lc8qxHkp]
  
  multiset<ll> ms;
  REP(i, 0, N) ms.insert(A[i]);
  ll cnt = 0;
  while (SIZE(ms) > 1) {
    ll a = *ms.begin();
    auto it = ms.end();
    it--;
    ll b = *it;
    ms.erase(it);
    ll x = b % a;
    if (x > 0) ms.insert(x);
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}

