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

  auto solve = [&]() -> ll {
    ll H, W; cin >> H >> W;
    string S; cin >> S;
    ll nd = 0, nr = 0, nq = 0;
    ll N = ssize(S);
    REP(i, 0, N) {
      if (S[i] == 'D') nd++;
      else if (S[i] == 'R') nr++;
      else if (S[i] == '?') nq++;
      else assert(0);
    }
    vector<ll> P1(H), P2(H);
    ll ud = 0, ur = 0;
    ll x = 0, y = 0;
    P1[0] = 0;
    REP(i, 0, N) {
      if (S[i] == 'D') {
        x++;
        P1[x] = y;
      }else if (S[i] == 'R') {
        y++;
      }else if (S[i] == '?') {
        if (nd + ud < H - 1) {
          x++;
          P1[x] = y;
          ud++;
        }else {
          y++;
        }
      }else assert(0);
    }
    x = 0; y = 0;
    P2[0] = 0;
    REP(i, 0, N) {
      if (S[i] == 'D') {
        x++;
        P2[x] = y;
      }else if (S[i] == 'R') {
        y++;
        P2[x] = y;
      }else if (S[i] == '?') {
        if (nr + ur < W - 1) {
          y++;
          P2[x] = y;
          ur++;
        }else {
          x++;
          P2[x] = y;
        }
      }else assert(0);
    }
    ll ans = 0;
    REP(j, 0, H) ans += P2[j] - P1[j] + 1;
    return ans;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

