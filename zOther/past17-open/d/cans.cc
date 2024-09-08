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

  ll A, B, C; cin >> A >> B >> C;
  // @InpVec(12, X) [FcpDvfD4]
  auto X = vector(12, ll());
  for (int i = 0; i < 12; i++) { ll v; cin >> v; X[i] = v; }
  // @End [FcpDvfD4]

  ll ca = 0, cb = B, cc = C;
  REP(i, 0, 12) {
    ca += A * max(0LL, X[i] - 3);
    cb += A * max(0LL, X[i] - 50);
  }
  cout << min(ca, min(cb, cc)) << endl;

  return 0;
}

