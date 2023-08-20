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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  // @InpGrid(H, W, C, char) [K5TGxWyu]
  auto C = vector(H, vector(W, char()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { char v; cin >> v; C[i][j] = v; }
  // @End [K5TGxWyu]

  vector SR(H, vector(26, 0LL));
  vector SC(W, vector(26, 0LL));
  vector TR(H, 0LL);
  vector TC(W, 0LL);
  REP(i, 0, H) REP(j, 0, W) {
    ll d = C[i][j] - 'a';
    SR[i][d]++;
    SC[j][d]++;
  }
  REP(i, 0, H) REP(d, 0, 26) if (SR[i][d] > 0) TR[i]++;
  REP(j, 0, W) REP(d, 0, 26) if (SC[j][d] > 0) TC[j]++;
  vector<ll> candR;
  vector<ll> candC;
  REP(i, 0, H) if (TR[i] == 1) candR.push_back(i);
  REP(j, 0, W) if (TC[j] == 1) candC.push_back(j);

  auto gsum = [&](auto& vec) -> ll {
    ll a = 0;
    REP(i, 0, 26) a += vec[i];
    return a;
  };

  vector<bool> badR(H);
  vector<bool> badC(W);

  while (not candR.empty() or not candC.empty()) {
    vector<ll> candR2, candC2;
    for (ll i : candR) {
      if (gsum(SR[i]) >= 2) candR2.push_back(i);
      else badR[i] = true;
    }
    for (ll j : candC) {
      if (gsum(SC[j]) >= 2) candC2.push_back(j);
      else badC[j] = true;
    }
    candR.resize(0);
    candC.resize(0);
    for (ll i : candR2) {
      REP(j, 0, W) if (C[i][j] != '*') {
        ll d = C[i][j] - 'a';
        if (--SC[j][d] == 0) {
          if (--TC[j] == 1 and not badC[j]) candC.push_back(j);
        }
        C[i][j] = '*';
      }
    }
    for (ll j : candC2) {
      REP(i, 0, H) if (C[i][j] != '*') {
        ll d = C[i][j] - 'a';
        if (--SR[i][d] == 0) {
          if (--TR[i] == 1 and not badR[i]) candR.push_back(i);
        }
        C[i][j] = '*';
      }
    }
  }
  ll ans = 0;
  REP(i, 0, H) REP(j, 0, W) if (C[i][j] != '*') ans++;
  cout << ans << endl;

  return 0;
}

