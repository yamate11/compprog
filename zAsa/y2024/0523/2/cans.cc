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
  ll a = 3;
  REP(i, 1, 100) {
    
    ll b = 5;
    REP(j, 1, 100) {
      if (a + b == N) {
        cout << i << " " << j << endl;
        return 0;
      }else if (a + b > N) {
        break;
      }else if (b > N / 5) {
        break;
      }
      b *= 5;
    }
    if (a > N / 3) break;
    a *= 3;
  }
  cout << -1 << endl;
  return 0;
}

