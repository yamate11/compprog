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

  ll B1, R1, B2, R2, T; cin >> B1 >> R1 >> B2 >> R2 >> T;
  ll ans = 0;

  auto func = [&](ll t, ll B, ll R) -> bool {
    ll x = t % (B + R);
    if (x < B) return true;
    else return false;
  };

  REP(t, 0, T) {
    ll b1 = func(t, B1, R1);
    ll b2 = func(t, B2, R2);
    if (b1 and b2) ans++;
  }
  cout << ans << endl;

  return 0;
}

