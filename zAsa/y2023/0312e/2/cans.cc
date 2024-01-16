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

  string S; cin >> S;
  ll N = SIZE(S);
  ll K; cin >> K;
  K = min(K, N*(N+1)/2);
  vector tbl_init(K + 1, vector(N + 1, vector(N + 1, vector(N + 1, 0LL))));
  auto tbl = tbl_init;
  ll maxk = 0;
  tbl[0][0][0][0] = 1;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    char c = S[i];
    ll new_maxk = maxk;
    REP(k, 0, maxk + 1) REP(ik, 0, i + 1) REP(ie, 0, i + 1) REP(iy, 0, i + 1) {
      ll val = prev[k][ik][ie][iy];
      if (val == 0) continue;
      if (c == 'K') {
        REP(j, 0, ik + 1) {
          ll new_ie = j <= ie ? ie + 1 : ie;
          ll new_iy = j <= iy ? iy + 1 : iy;
          if (k + j <= K) {
            tbl[k + j][j][new_ie][new_iy] += val;
            new_maxk = max(new_maxk, k + j);
          }
        }
      }else if (c == 'E') {
        REP(j, 0, ie + 1) {
          ll new_ik = j <= ik ? ik + 1 : ik;
          ll new_iy = j <= iy ? iy + 1 : iy;
          if (k + j <= K) {
            tbl[k + j][new_ik][j][new_iy] += val;
            new_maxk = max(new_maxk, k + j);
          }
        }
      }else if (c == 'Y') {
        REP(j, 0, iy + 1) {
          ll new_ik = j <= ik ? ik + 1 : ik;
          ll new_ie = j <= ie ? ie + 1 : ie;
          if (k + j <= K) {
            tbl[k + j][new_ik][new_ie][j] += val;
            new_maxk = max(new_maxk, k + j);
          }
        }
      }
    }
    maxk = new_maxk;
  }
  ll ans = 0;
  REP(k, 0, K + 1) REP(ik, 0, N + 1) REP(ie, 0, N + 1) REP(iy, 0, N + 1) ans += tbl[k][ik][ie][iy];
  cout << ans << endl;

  return 0;
}

