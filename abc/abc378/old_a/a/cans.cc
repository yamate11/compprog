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

  // @InpVec(4, A, dec=1) [PjIAQRKz]
  auto A = vector(4, ll());
  for (int i = 0; i < 4; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [PjIAQRKz]

  vector cnt(4, 0LL);
  REP(i, 0, 4) cnt[A[i]]++;
  ll ans = 0;
  REP(i, 0, 4) {
    ans += cnt[i] / 2;
  }
  cout << ans << endl;
  return 0;
}

