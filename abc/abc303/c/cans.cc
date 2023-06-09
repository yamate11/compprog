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

  ll N, M, H, K; cin >> N >> M >> H >> K;
  string S; cin >> S;
  set<pll> ss;
  REP(i, 0, M) {
    ll x, y; cin >> x >> y;
    ss.emplace(x, y);
  }
  ll cx = 0, cy = 0;
  ll z = H;
  REP(i, 0, N) {
    if (S[i] == 'R') cx++;
    else if (S[i] == 'L') cx--;
    else if (S[i] == 'U') cy++;
    else if (S[i] == 'D') cy--;
    else assert(0);
    z--;
    if (z < 0) {
      cout << "No\n";
      return 0;
    }
    if (z < K and ss.find(pll(cx, cy)) != ss.end()) {
      z = K;
      ss.erase(pll(cx, cy));
    }
  }
  cout << "Yes\n";

  return 0;
}

