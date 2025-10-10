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

  auto f = [&](ll a) -> ll {
    ll ret = 0;
    while (a > 0) {
      ret += a % 10;
      a /= 10;
    }
    return ret;
  };

  

  ll N, A, B; cin >> N >> A >> B;
  ll sum = 0;
  REP(i, 1, N + 1) {
    ll t = f(i);
    if (A <= t and t <= B) sum += i;
  }
  cout << sum << endl;
  return 0;
}

