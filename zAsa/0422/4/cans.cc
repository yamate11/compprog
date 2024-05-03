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

  vector pow10(19, 0LL);
  pow10[0] = 1;
  REP(i, 1, 19) pow10[i] = 10 * pow10[i - 1];

  set<ll> A;
  REP(d, -9, 10) {
    REP(a, 0, 10) {
      REP(n, 1, 18) {
        ll z = a + d * (n - 1);
        if (0 <= z and z < 10) {
          ll p = a;
          ll x = 0;
          REP(i, 0, n) {
            x += p * pow10[i];
            p += d;
          }
          A.insert(x);
        }
      }
    }
  }
  ll y = 0;
  REP(i, 0, 18) y += pow10[i];
  A.insert(y);

  ll X; cin >> X;
  auto it = A.lower_bound(X);
  cout << *it << endl;
  

  return 0;
}

