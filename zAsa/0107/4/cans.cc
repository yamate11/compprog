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

  ll H, W, N; cin >> H >> W >> N;
  ll h, w; cin >> h >> w;
  vector A(N, vector(H + 1, vector(W + 1, 0)));
  REP(i, 0, H) REP(j, 0, W) {
    ll a; cin >> a; a--;
    A[a][i + 1][j + 1] = 1;
  }
  REP(a, 0, N) REP(i, 1, H + 1) REP(j, 1, W + 1) A[a][i][j] += A[a][i - 1][j];
  REP(a, 0, N) REP(i, 1, H + 1) REP(j, 1, W + 1) A[a][i][j] += A[a][i][j - 1];
  auto f = [&](ll a, ll i, ll j, ll x, ll y) -> ll {
    return A[a][i][j] + A[a][i + x][j + y] - A[a][i + x][j] - A[a][i][j + y];
  };

#if DEBUG
  auto showA = [&](ll a) -> void {
    REP(i, 0, H + 1) {
      REP(j, 0, W + 1) cerr << A[a][i][j] << " ";
      cerr << endl;
    }
    cerr << endl;
  };
  showA(0);
  showA(1);
  showA(2);
  showA(3);
  showA(4);
#endif

  REP(i, 0, H - h + 1) {
    REP(j, 0, W - w + 1) {
      ll s = 0;
      REP(a, 0, N) {
        if (f(a, 0, 0, H, W) > f(a, i, j, h, w)) s++;
      }
      cout << s << " ";
    }
    cout << "\n";
  }

  return 0;
}

