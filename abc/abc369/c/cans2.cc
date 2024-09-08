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
  // @InpVec(N, A) [DiBHNVC9]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [DiBHNVC9]

  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }else if (N == 2) {
    cout << 3 << endl;
    return 0;
  }

  vector<ll> B(N - 1);
  REP(i, 0, N - 1) B[i] = A[i + 1] - A[i];
  
  ll ans = N;
  ll p = 0;
  while (p < N - 1) {
    ll q = p + 1;
    while (q < N - 1 and B[q] == B[p]) q++;
    ll r = q - p + 1;
    ans += r * (r - 1) / 2;
    p = q;
  }
  cout << ans << endl;


  return 0;
}

