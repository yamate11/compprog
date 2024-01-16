#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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

  ll A, B, C; cin >> A >> B >> C;
  ll a = A % 10;
  ll b = B % 4;
  ll k;
  if (b == 0) k = 4;
  else if (b == 1) k = 1;
  else if (b == 3) {
    if (C % 2 == 0) k = 1;
    else k = 3;
  }else if (b == 2) {
    if (C == 1) k = 2;
    else k = 4;
  }else assert(0);
  ll ans = 1;
  REP(i, 0, k) {
    ans = (ans * a) % 10;
  }
  cout << ans << endl;
  return 0;
}

