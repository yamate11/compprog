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

  ll N, K; cin >> N >> K;
  // @InpMVec(K, (T, P)) [10GT1Lz5]
  auto T = vector(K, ll());
  auto P = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; P[i] = v2;
  }
  // @End [10GT1Lz5]
  // @InpVec(N, C) [sOYDOG1v]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [sOYDOG1v]

  ll tot = accumulate(ALL(C), 0LL);
  ll k = ranges::lower_bound(T, tot + 1) - T.begin();
  ll red = P[k - 1] * tot / 100;
  cout << tot - red << endl;


  return 0;
}

