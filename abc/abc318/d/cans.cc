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

using ull = unsigned long long;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  auto D = vector(N, vector(N, 0LL));
  REP(i, 0, N - 1) {
    REP(j, 0, N - 1 - i) {
      ll d; cin >> d;
      D[i][i + 1 + j] = D[i + 1 + j][i] = d;
    }
  }
  auto tbl = vector(1LL << N, -1LL);
  auto f = [&](auto rF, ll x) -> ll {
    ll& ret = tbl[x];
    if (ret < 0) {
      if (x == 0 or popcount(ull(x)) == 1) ret = 0;
      else {
        ret = 0;
        REP(i, 0, N) {
          if (x >> i & 1) {
            REP(j, i + 1, N) {
              if (x >> j & 1) ret = max(ret, D[i][j] + rF(rF, x ^ ((1LL << i) | (1LL << j))));
            }
          }
        }
      }
    }
    return ret;
  };

  cout << f(f, (1LL << N) - 1) << endl;

  return 0;
}

