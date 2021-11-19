#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll K; cin >> K;

  ll sz = SIZE(S);
  vector<ll> C(sz), P(sz);
  vector<ll> N(3);
  REP(i, sz) {
    ll code = (S[i] == 'K') ? 0 : (S[i] == 'E') ? 1 : 2;
    C[i] = code;
    N[code]++;
    P[i] = N[code];
  }

  ll T = min(sz*sz, K);
  vector tbl_init(T + 1, vector(N[0] + 1, vector(N[1] + 1, 0LL)));
  auto tbl = tbl_init;
  tbl[0][0][0] = 1;
  REP(i, sz) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(t, T + 1) REP(k, N[0] + 1) REP(e, N[1] + 1) {
      if (k + e > i) continue;
      if (prev[t][k][e] == 0) continue;
      vector<ll> d({k, e, i - (k + e)});
      ll ord = 0;
      vector<ll> ve(3, -1LL);
      REP(j, sz) {
        ll code = C[j];
        if (P[j] <= d[code]) continue;
        else {
          if (P[j] == d[code] + 1) ve[code] = ord;
          ord++;
        }
      }
      REP(code, 3) {
        if (ve[code] < 0) continue;
        ll tt = t + ve[code];
        if (tt > T) continue;
        ll kk = k + (code == 0 ? 1 : 0);
        ll ee = e + (code == 1 ? 1 : 0);
        tbl[tt][kk][ee] += prev[t][k][e];
      }
    }
  }
  ll ans = 0;
  REP(t, T+1) REP(k, N[0]+1) REP(e, N[1]+1) ans += tbl[t][k][e];
  cout << ans << endl;

  return 0;
}

