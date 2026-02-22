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
  // @InpVec(N, A) [Qr5p5VDO]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Qr5p5VDO]

  vector<ll> vec(N);
  vec[0] = 0;
  REP(i, 1, N) {
    vec[i] = 2 * A[i - 1] - vec[i - 1];
  }
  ll diff = 2 * A[N - 1] - (vec[0] + vec[N - 1]);
  vec[0] = diff / 2;
  REP(i, 1, N) {
    vec[i] = 2 * A[i - 1] - vec[i - 1];
  }
  REPOUT(i, 0, N, vec[i], " ");
    

  return 0;
}

