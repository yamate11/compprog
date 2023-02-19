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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  if (N == 3) {
    cout << "4 2 6\n5 7 8\n3 9 1\n";
    return 0;
  }
  vector ans(N, vector(N, 0LL));
  ll x = 0;
  REP(i, 0, N) REP(j, 0, N) {
    if (x + 2 > N*N) x = 1;
    else x += 2;
    ans[i][j] = x;
  }

  auto arrange = [&](ll v, ll r, ll c, ll r0) -> void {
    REP(i, 0, N) {
      ll rem = (v + ans[r0][i]) % 6;
      if (rem != 1 and rem != 5) {
        swap(ans[r][c], ans[r0][i]);
        return;
      }
    }
    assert(0);
  };

  ll h = N / 2;
  if (N % 2 == 1) {
    swap(ans[h][h], ans[N-1][N-1]);
    arrange(ans[h][h], h, h - 1, 0);
    REP(i, 0, h) arrange(ans[h][i], h + 1, i, N-1);
    REP(i, h, N) arrange(ans[h][i], h - 1, i, 0);
  }else {
    swap(ans[h][0], ans[N-1][2]);
    REP(i, 0, N) arrange(ans[h][i], h - 1, i, 0);
  }
  REP(i, 0, N) REPOUT(j, 0, N, ans[i][j], " ");
  return 0;
}

