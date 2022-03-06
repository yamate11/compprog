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

  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) {cin >> A[i]; A[i]--; }
  ll Q; cin >> Q;
  using sta = tuple<ll, ll, ll, ll>; // block, R, L, q
  vector<sta> LR(Q);
  ll K = llround(sqrt(Q));
  REP(q, Q) {
    ll l, r; cin >> l >> r; l--;
    ll block = l / K;
    LR.emplace_back(block, r, l, q);
  }
  sort(ALL(LR));
  vector<ll> rec(N);
  ll cnt = 0;
  ll cl = 0, cr = 0;
  vector<ll> ans(Q);
  for (auto [dummy, r, l, q] : LR) {
    while (cr < r) {
      ll a = A[cr];
      rec[a]++;
      if (rec[a] % 2 == 0) cnt++;
      cr++;
    }
    while (l < cl) {
      cl--;
      ll a = A[cl];
      rec[a]++;
      if (rec[a] % 2 == 0) cnt++;
    }
    while (r < cr) {
      cr--;
      ll a = A[cr];
      rec[a]--;
      if (rec[a] % 2 != 0) cnt--;
    }
    while (cl < l) {
      ll a = A[cl];
      rec[a]--;
      if (rec[a] % 2 != 0) cnt--;
      cl++;
    }
    ans[q] = cnt;
  }
  REP(q, Q) cout << ans[q] << "\n";

  return 0;
}

