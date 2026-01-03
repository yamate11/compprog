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
  // @InpVec(N, A) [Ytl38pOS]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Ytl38pOS]
  string S; cin >> S;
  vector vec1(N, vector<ll>(3));
  vector vec2(N, vector<ll>(3));
  REP(i, 0, N) {
    if (i > 0) vec1[i] = vec1[i - 1];
    if (S[i] == 'M') vec1[i][A[i]]++;
  }
  REPrev(i, N - 1, 0) {
    if (i < N - 1) vec2[i] = vec2[i + 1];
    if (S[i] == 'X') vec2[i][A[i]]++;
  }
  auto mex = [&](ll x, ll y, ll z) -> ll {
    vector V(3, 0LL);
    V[x]++;
    V[y]++;
    V[z]++;
    if (V[0] == 0) return 0;
    if (V[1] == 0) return 1;
    if (V[2] == 0) return 2;
    return 3;
  };

  ll ans = 0;
  REP(i, 0, N) {
    if (S[i] == 'E') {
      REP(j, 0, 3) REP(k, 0, 3) ans += mex(A[i], j, k) * vec1[i][j] * vec2[i][k];
    }
  }
  cout << ans << endl;
  return 0;
}

