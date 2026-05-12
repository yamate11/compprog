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

  ll N, P, T, C; cin >> N >> P >> T >> C;
  // @InpVec(N - 1, S) [bhvP7bPy]
  auto S = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; S[i] = v; }
  // @End [bhvP7bPy]

  if (P >= T) {
    cout << 0 << endl;
    return 0;
  }

  if (N == 1) {
    cout << -1 << endl;
    return 0;
  }

  ll x = *ranges::max_element(S);
  if (T <= x) {
    cout << C << endl;
  }else {
    cout << -1 << endl;
  }
  

  return 0;
}

