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

  ll N, X; cin >> N >> X;
  // @InpMVec(N, (A, B)) [gz3N29e8]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [gz3N29e8]
  vector<bool> vec(X + 1);
  vec[0] = true;
  REP(i, 0, N) {
    REPrev(j, X, 0) {
      if (vec[j]) {
        REP(k, 1, B[i] + 1) {
          ll x = j + A[i] * k;
          if (x > X) break;
          if (vec[x]) break;
          vec[x] = true;
        }
      }
    }
  }
  if (vec[X]) cout << "Yes\n";
  else cout << "No\n";


  return 0;
}

