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

  ll N, M; cin >> N >> M;
  string S; cin >> S;
  string T; cin >> T;
  // @InpMVec(M, ((L, dec=1), (R, dec=0))) [tVlnkbXJ]
  auto L = vector(M, ll());
  auto R = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 0; R[i] = v2;
  }
  // @End [tVlnkbXJ]

  vector<bool> vec(N + 1, false);
  REP(i, 0, M) {
    vec[L[i]] = not vec[L[i]];
    vec[R[i]] = not vec[R[i]];
  }
  string ans;
  bool mode = false;
  REP(i, 0, N) {
    if (vec[i]) mode = not mode;
    if (mode) ans += T[i];
    else      ans += S[i];
  }
  cout << ans << endl;

  return 0;
}

