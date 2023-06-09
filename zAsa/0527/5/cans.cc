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
  // @InpVec(N, A) [6F3pchOp]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [6F3pchOp]

  ll p = 0; ll q = 0;
  ll lim = ll(1e5) + 1;
  vector<ll> cnt(lim);
  ll ans = 0;
  while (true) {
    while (q < N and cnt[A[q]] == 0) {
      cnt[A[q]]++;
      q++;
    }
    ans = max(ans, q - p);
    if (q == N) break;
    cnt[A[p]]--;
    p++;
  }
  cout << ans << endl;

  return 0;
}

