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
  ll aa = 1;
  REP(a, 1, 100) {
    if (aa <= N / 3) {
      aa *= 3;
      ll x = N - aa;
      ll bb = 1;
      REP(b, 1, 100) {
        if (bb <= x / 5) {
          bb *= 5;
          if (bb == x) {
            cout << a << " " << b << endl;
            return 0;
          }
        }else {
          break;
        }
      }
    }else {
      break;
    }
  }
  cout << -1 << endl;

  return 0;
}

