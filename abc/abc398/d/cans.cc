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

  ll N, R, C; cin >> N >> R >> C;
  string S; cin >> S;
  set<pll> ss;
  ll ox = 0, oy = 0;
  ll tx = R, ty = C;
  ll dx, dy;
  ss.emplace(ox, oy);
  string ans(N, ' ');
  REP(i, 0, N) {
    if (S[i] == 'N') { dy =  0; dx =  1; }
    if (S[i] == 'S') { dy =  0; dx = -1; }
    if (S[i] == 'E') { dy = -1; dx =  0; }
    if (S[i] == 'W') { dy =  1; dx =  0; }
    ox += dx;
    oy += dy;
    tx += dx;
    ty += dy;
    ss.emplace(ox, oy);
    if (ss.contains(pll(tx, ty))) {
      ans[i] = '1';
    }else {
      ans[i] = '0';
    }
  }
  cout << ans << endl;
  return 0;
}

