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
  // @InpVec(N, A, dec=1) [aPZyQQeP]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [aPZyQQeP]
  
  vector cnt(N, 0LL);
  REP(i, 0, N) cnt[A[i]]++;

  auto f = [&](ll x) -> ll { return x * (x - 1) / 2; };

  ll s = 0;
  REP(i, 0, N) s += f(cnt[i]);
  REP(k, 0, N) {
    ll t = A[k];
    cout << s - f(cnt[t]) + f(cnt[t] - 1) << "\n";
  }

  return 0;
}

