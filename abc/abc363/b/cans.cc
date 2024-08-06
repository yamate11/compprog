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

  ll N, T, P; cin >> N >> T >> P;
  // @InpVec(N, L) [CcdDfs9E]
  auto L = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; L[i] = v; }
  // @End [CcdDfs9E]
  sort(ALL(L), greater<ll>());
  ll x = L[P - 1];
  if (x >= T) {
    cout << "0\n";
  }else {
    cout << T - x << endl;
  }

  return 0;
}

