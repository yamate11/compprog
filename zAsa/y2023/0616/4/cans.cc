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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1))) [xObq80UP]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
  }
  // @End [xObq80UP]
  vector fr(N, vector(N, false));
  REP(i, 0, M) {
    fr[A[i]][B[i]] = true;
    fr[B[i]][A[i]] = true;
  }

  REP(i, 0, N) {
    vector<bool> rec(N);
    REP(j, 0, N) {
      if (j == i) continue;
      if (not fr[i][j]) continue;
      REP(k, 0, N) {
        if (k == i or k == j) continue;
        if (fr[j][k]) rec[k] = true;
      }
    }
    ll a = 0;
    REP(j, 0, N) if (rec[j] and not fr[i][j]) a++;
    cout << a << endl;
  }
  

  return 0;
}

