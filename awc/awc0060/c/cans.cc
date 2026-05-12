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
  // @InpMVec(N, (P, Q)) [WwjUo9A6]
  auto P = vector(N, ll());
  auto Q = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; Q[i] = v2;
  }
  // @End [WwjUo9A6]

  ll a = P[0];
  ll b = Q[0];
  REP(i, 1, N) {
    a = lcm(a, P[i]);
    b = gcd(b, Q[i]);
  }
  cout << a << " " << b << "\n";

  return 0;
}

