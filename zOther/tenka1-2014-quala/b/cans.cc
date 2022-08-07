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
  ll N = SIZE(S);
  using ev_t = tuple<ll,ll,ll,ll>;
  vector<ev_t> event;
  enum {ON, THR, DMG, BACK, NORM, CUM};
  for (ll i = 0; i < N; i++) {
    if (S[i] == 'N') {
      event.emplace_back(i, ON, NORM, i);
      event.emplace_back(i, THR, NORM, i);
      event.emplace_back(i + 1, DMG, NORM, i);
      event.emplace_back(i + 6, BACK, NORM, i);
    }else if (S[i] == 'C') {
      event.emplace_back(i, ON, CUM, i);
      event.emplace_back(i + 2, THR, CUM, i);
      event.emplace_back(i + 3, DMG, CUM, i);
      event.emplace_back(i + 8, BACK, CUM, i);
    }
  }
  sort(ALL(event));
  ll combo = 0;
  ll k = 5;
  vector<ll> vdmg(N);
  ll ans = 0;
  for (auto [_, op, tp, idx] : event) {
    if (op == ON) {
      ll k0 = tp == NORM ? 1 : 3;
      if (k >= k0) {
        ll c = tp == NORM ? 1 : 5;
        vdmg[idx] = c * (10 + combo / 10);
        k -= k0;
      }
    }else if (op == DMG) {
      if (vdmg[idx] == 0) continue;
      ans += vdmg[idx];
      combo++;
    }else if (op == BACK) {
      if (vdmg[idx] == 0) continue;
      ll k0 = tp == NORM ? 1 : 3;
      k += k0;
    }
  }
  cout << ans << endl;

  return 0;
}

