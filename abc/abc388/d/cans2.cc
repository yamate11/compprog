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

  ll N; cin >> N;
  // @InpVec(N, A) [Y19Z0Byo]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Y19Z0Byo]

  vector<ll> D(N, 0LL);
  vector<ll> has(N, 0LL);

  ll cur = 0;
  REP(i, 0, N) {
    ll x = A[i] + cur;
    has[i] = x;
    if (i + x < N) D[i + x]++;
    cur = cur + 1 - D[i];
  }
  REPOUT(i, 0, N, max(0LL, has[i] - (N - i - 1)), " ");

  return 0;
}

