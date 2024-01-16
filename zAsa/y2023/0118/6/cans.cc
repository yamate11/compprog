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

  ll R, C; cin >> R >> C;
  // @InpGrid(R, C - 1, A) [JalGrpAN]
  auto A = vector(R, vector(C - 1, ll()));
  for (int i = 0; i < R; i++) for (int j = 0; j < C - 1; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [JalGrpAN]
  // @InpGrid(R-1, C, B) [T22sfHCu]
  auto B = vector(R-1, vector(C, ll()));
  for (int i = 0; i < R-1; i++) for (int j = 0; j < C; j++) { ll v; cin >> v; B[i][j] = v; }
  // @End [T22sfHCu]
  using sta = tuple<ll, ll, ll>;
  ll big = 1e18;
  vector dist(2, vector(R, vector(C, big)));
  using stb = tuple<ll, sta>;
  priority_queue<stb, vector<stb>, greater<stb>> pque;
  dist[0][0][0] = 0;
  pque.emplace(0, sta(0, 0, 0));
  auto op = [&](ll tp, ll r, ll c, ll l) -> void {
    if (l < dist[tp][r][c]) {
      dist[tp][r][c] = l;
      pque.emplace(l, sta(tp, r, c));
    }
  };
  while (not pque.empty()) {
    auto [l, p] = pque.top(); pque.pop();
    auto [tp, r, c] = p;
    if (dist[tp][r][c] == l) {
      if (tp == 0) {
        if (c + 1 < C) op(0, r, c + 1, l + A[r][c]);
        if (c - 1 >= 0) op(0, r, c - 1, l + A[r][c - 1]);
        if (r + 1 < R) op(0, r + 1, c, l + B[r][c]);
        op(1, r, c, l + 1);
      }else if (tp == 1) {
        if (r - 1 >= 0) op(1, r - 1, c, l + 1);
        op(0, r, c, l);
      }else assert(0);
    }
  }
  cout << dist[0][R - 1][C - 1] << endl;

  return 0;
}

