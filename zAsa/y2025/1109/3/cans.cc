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

  ll N, X, Y; cin >> N >> X >> Y;
  
  auto fred = [&](auto rFred, auto rFblue, ll n) -> ll {
    if (n == 1) return 0;
    return rFred(rFred, rFblue, n - 1) + X * rFblue(rFred, rFblue, n);
  };
  auto fblue = [&](auto rFred, auto rFblue, ll n) -> ll {
    if (n == 1) return 1;
    return rFred(rFred, rFblue, n - 1) + Y * rFblue(rFred, rFblue, n - 1);
  };
  cout << fred(fred, fblue, N) << endl;

  return 0;
}

