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

  string A; cin >> A;
  ll n = ssize(A);
  ll cnt = 0;
  REP(i, 0, n / 2) if (A[i] == A[n - 1 - i]) cnt++;
  if (cnt < n / 2 - 2) {
    cout << 25 * n << endl;
    return 0;
  }
  if (cnt == n / 2 - 1) {
    cout << 25 * n - 2 << endl;
    return 0;
  }
  if (n % 2 == 0) {
    cout << 25 * n << endl;
    return 0;
  }else {
    cout << 25 * (n - 1) << endl;
    return 0;
  }

  return 0;
}

