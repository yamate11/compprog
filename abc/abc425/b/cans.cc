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
  // @InpVec(N, A, dec=1) [1S6nz1nn]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [1S6nz1nn]

  vector<bool> app(N);
  REP(i, 0, N) {
    if (A[i] >= 0) {
      if (app[A[i]]) {
        cout << "No\n";
        return 0;
      }else {
        app[A[i]] = true;
      }
    }
  }
  ll x = 0;
  REP(i, 0, N) {
    if (A[i] < 0) {
      while (app[x]) x++;
      A[i] = x;
      app[x] = true;
    }
  }
  cout << "Yes\n";
  REPOUT(i, 0, N, A[i] + 1, " ");

  return 0;
}

