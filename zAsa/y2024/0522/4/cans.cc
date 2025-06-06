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
  string S, T; cin >> S >> T;
  ll p = 0;
  ll ans = 0;
  REP(q, 0, N) {
    if (T[q] == '0') {
      while (p < N and S[p] == '1') p++;
      if (p == N) {
        cout << -1 << endl;
        return 0;
      }
      if (p != q) ans++;
      p++;
    }
  }
  while (p < N and S[p] == '1') p++;
  if (p < N) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;

  return 0;
}

