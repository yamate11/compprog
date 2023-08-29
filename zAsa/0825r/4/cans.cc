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
  // @InpVec(N, A) [5IlaMUmP]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [5IlaMUmP]

  vector<ll> B(N);
  B[0] = A[0];
  REP(i, 1, N) B[i] = A[i] - B[i - 1];
  map<ll, ll> mp_e, mp_o;
  REP(i, 0, N) {
    if (i % 2 == 0) mp_e[B[i]]++;
    else mp_o[B[i]]++;
  }
  ll ans = mp_e[0] + mp_o[0];
  REP(i, 0, N) {
    if (i % 2 == 0) {
      mp_e[B[i]]--;
      ans += mp_e[B[i]] + mp_o[-B[i]];
    }
    else {
      mp_o[B[i]]--;
      ans += mp_o[B[i]] + mp_e[-B[i]];
    }
  }
  cout << ans << endl;
  

  return 0;
}

