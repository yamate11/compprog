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

  ll n, s, k; cin >> n >> s >> k;
  // @InpVec(n, D) [yT2b6emX]
  auto D = vector(n, ll());
  for (int i = 0; i < n; i++) { ll v; cin >> v; D[i] = v; }
  // @End [yT2b6emX]
  ll tot = accumulate(ALL(D), 0LL);
  cout << s + n * k + tot << endl;

  return 0;
}

