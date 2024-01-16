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

  ll H, W, C, Q; cin >> H >> W >> C >> Q;
  vector<bool> row(H), col(W);
  ll nR = 0, nC = 0;
  // @InpMVec(Q, (vt, (vn, dec=1), (vc, dec=1))) [VkZKM0mx]
  auto vt = vector(Q, ll());
  auto vn = vector(Q, ll());
  auto vc = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; vt[i] = v1;
    ll v2; cin >> v2; v2 -= 1; vn[i] = v2;
    ll v3; cin >> v3; v3 -= 1; vc[i] = v3;
  }
  // @End [VkZKM0mx]
  vector<ll> ans(C, 0LL);
  REPrev(q, Q - 1, 0) {
    ll t = vt[q], n = vn[q], c = vc[q];
    if (t == 1) {
      if (not row[n]) {
        row[n] = true;
        nR++;
        ans[c] += W - nC;
      }
    }else if (t == 2) {
      if (not col[n]) {
        col[n] = true;
        nC++;
        ans[c] += H - nR;
      }
    }else assert(0);
  }
  REPOUT(i, 0, C, ans[i], " ");

  return 0;
}

