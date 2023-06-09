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
  // @InpVec(N, A) [9yWIlmsg]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [9yWIlmsg]
  ll ans = 0;
  ll sp = 0, sx = 0;
  ll l = 0, r = 0;
  while (l < N) {
    if (r < N and (sp + A[r]) == (sx ^ A[r])) {
      sp += A[r];
      sx = (sx ^ A[r]);
      r++;
    }else {
      ll len = r - l;
      ans += len;
      sp -= A[l];
      sx = (sx ^ A[l]);
      l++;
    }
  }
  cout << ans << endl;

  return 0;
}

