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

  // @InpVec(5, A) [iCrXErny]
  auto A = vector(5, ll());
  for (int i = 0; i < 5; i++) { ll v; cin >> v; A[i] = v; }
  // @End [iCrXErny]

  vector<ll> cand;
  REP(x, 0, 32) {
    if (__builtin_popcountll(x) == 3) {
      ll s = 0;
      REP(i, 0, 5) if (x >> i & 1) s += A[i];
      cand.push_back(s);
    }
  }
  sort(ALL(cand), greater<ll>());
  unique(ALL(cand));
  cout << cand[2] << endl;

  return 0;
}

