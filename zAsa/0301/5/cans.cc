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
  // @InpVec(N, A) [xzLx39Mf]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [xzLx39Mf]

  auto solve = [&]() -> ll {
    ll ans = 0;
    if (A[0] != 0) return -1;
    REPrev(i, N-1, 1) {
      if (A[i] > 0) {
        ans++;
        if (A[i - 1] < A[i] - 1) return -1;
        else if (A[i - 1] == A[i] - 1) ;
        else if (A[i - 1] >= A[i]) ans += A[i] - 1;
      }
    }
    return ans;
    
  };
  cout << solve() << endl;

  return 0;
}

