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
  // @InpVec(N, A) [aEq8XIMq]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [aEq8XIMq]

  vector<ll> B{0};
  REP(i, 0, N) B.push_back(A[i]);
  B.push_back(0);

  ll tot = 0;
  REP(i, 0, N + 2 - 1) tot += abs(B[i + 1] - B[i]);
  REP(i, 0, N) {
    ll orig = abs(B[i + 1] - B[i]) + abs(B[i + 2] - B[i + 1]);
    ll chgd = abs(B[i + 2] - B[i]);
    cout << tot + chgd - orig << "\n";
  }

  return 0;
}

