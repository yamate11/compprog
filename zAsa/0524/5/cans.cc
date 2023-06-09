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
  vector tbl(101, vector(101, vector<double>(101, -10.0)));
  auto f = [&](auto rF, ll a, ll b, ll c) -> double {
    if (a == 100 or b == 100 or c == 100) return 0.0;
    double& ret = tbl[a][b][c];
    if (ret < -1) {
      ret = 1.0 + (a * rF(rF, a + 1, b, c) + b * rF(rF, a, b + 1, c) + c * rF(rF, a, b, c + 1)) / (a + b + c);
    }
    return ret;
  };
  cout << f(f, A, B, C) << endl;

  return 0;
}

