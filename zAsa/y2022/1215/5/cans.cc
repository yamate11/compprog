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
  // @InpVec(N, D) [3RhEVKMx]
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; D[i] = v; }
  // @End [3RhEVKMx]
  vector rec(13, 0LL);
  rec[0] = 1;
  REP(i, 0, N) {
    rec[D[i]]++;
    if (rec[D[i]] == 3 or rec[12] == 2 or rec[0] == 2) {
      cout << 0 << endl;
      return 0;
    }
  }
  vector vec(24, false);
  vec[0] = true;
  if (rec[12] == 1) vec[12] = true;
  vector<ll> pos;
  REP(i, 1, 12) {
    if (rec[i] == 2) vec[i] = vec[24 - i] = true;
    if (rec[i] == 1) pos.push_back(i);
  }
  ll sz = SIZE(pos);
  ll ans = 0;
  REP(x, 0, 1LL << sz) {
    REP(j, 0, sz) {
      ll i = pos[j];
      if (x >> j & 1) {
        vec[i] = true;
        vec[24 - i] = false;
      }else {
        vec[i] = false;
        vec[24 - i] = true;
      }
    }
    ll prev = -1;
    ll val = 100;
    REP(i, 0, 48) {
      if (vec[i % 24]) {
        if (prev >= 0) val = min(val, i - prev);
        prev = i;
      }
    }
    ans = max(ans, val);
  }
  cout << ans << endl;
  

  return 0;
}

