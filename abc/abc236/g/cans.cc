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

  ll N, T, L; cin >> N >> T >> L;
  ll ht = 64 - __builtin_clzll(L);
  vector fwd(T + 1, vector(N, bitset<100>()));
  REP2(t, 1, T + 1) {
    fwd[t] = fwd[t - 1];
    ll u, v; cin >> u >> v; u--; v--;
    fwd[t][u][v] = true;
  }

  auto func = [&](auto& base) -> bitset<100> {
    vector tbl(ht, vector(N, bitset<100>()));
    REP(i, N) tbl[0][i] = base[i];
    REP2(h, 1, ht) {
      REP(i, N) {
        REP(j, N) {
          if (tbl[h-1][i][j]) tbl[h][i] |= tbl[h-1][j];
        }
      }
    }
    bitset<100> bs;
    bs[0] = true;
    for (ll h = 0, x = L; x > 0; h++, x /= 2) {
      if (x % 2 == 1) {
        auto prev = bs;
        bs.reset();
        REP(i, N) if (prev[i]) bs |= tbl[h][i];
      }
    }
    return bs;
  };

  map<ll, bitset<100>> mp;
  auto binsch = [&](auto rF, ll tL, auto& bsL, ll tH, auto& bsH) -> void {
    if (tL + 1 == tH) {
      mp[tH] = bsH;
      return;
    }
    ll tM = (tL + tH) / 2;
    auto bsM = func(fwd[tM]);
    if (bsL != bsM) rF(rF, tL, bsL, tM, bsM);
    if (bsM != bsH) rF(rF, tM, bsM, tH, bsH);
  };
  bitset<100> dummy;
  bitset<100> top = func(fwd[T]);
  binsch(binsch, 0, dummy, T, top);
  vector<ll> ans(N, -1);
  bitset<100> prev;
  for (auto [t, bs] : mp) {
    REP(i, N) if (bs[i] and not prev[i]) ans[i] = t;
    prev = bs;
  }
  REP(i, N) cout << ans[i] << " ";
  cout << endl;


  

  return 0;
}

