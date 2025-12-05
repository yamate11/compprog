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

  ll N, A, B; cin >> N >> A >> B;
  string S; cin >> S;
  vector vA(N + 1, 0LL);
  vector vB(N + 1, 0LL);
  REP(i, 0, N) {
    if (S[i] == 'a') {
      vA[i + 1] = vA[i] + 1;
      vB[i + 1] = vB[i];
    }else {
      vA[i + 1] = vA[i];
      vB[i + 1] = vB[i] + 1;
    }
  }
  ll ans = 0;
  REP(i, 0, N) {
    ll p = ranges::lower_bound(vA, vA[i] + A) - vA.begin();
    ll q = ranges::lower_bound(vB, vB[i] + B) - vB.begin();
    if (q > p) ans += q - p;
  }
  cout << ans << endl;
  return 0;
}

