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
  // @InpMVec(N, (F, B)) [13kmAC8Z]
  auto F = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; F[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [13kmAC8Z]

  ll cur = accumulate(ALL(F), 0LL);
  vector<ll> inc(N);
  REP(i, 0, N) inc[i] = B[i] - F[i];
  ranges::sort(inc, greater<ll>());
  ll t = accumulate(inc.begin(), inc.begin() + K, 0LL);
  cout << cur + t << endl;

  return 0;
}

