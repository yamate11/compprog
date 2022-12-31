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

  ll H, W, C, Q; cin >> H >> W >> C >> Q;
  // @InpMVec(Q, (t, n, c)) [gZdCnY82]
  auto t = vector(Q, ll());
  auto n = vector(Q, ll());
  auto c = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; t[i] = v1;
    ll v2; cin >> v2; n[i] = v2;
    ll v3; cin >> v3; c[i] = v3;
  }
  // @End [gZdCnY82]
  set<ll> hs, ws;
  vector<ll> ans(C + 1);
  REPrev(q, Q - 1, 0) {
    if (t[q] == 1) {
      if (hs.find(n[q]) == hs.end()) {
        ans[c[q]] += W - SIZE(ws);
        hs.insert(n[q]);
      }
    }else if (t[q] == 2) {
      if (ws.find(n[q]) == ws.end()) {
        ans[c[q]] += H - SIZE(hs);
        ws.insert(n[q]);
      }
    }
  }
  REPOUT(i, 1, C + 1, ans[i], " ");

  return 0;
}

