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

  ll N; cin >> N;
  // @InpMVec(N, (H, L)) [pbTFTnYz]
  auto H = vector(N, ll());
  auto L = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; H[i] = v1;
    ll v2; cin >> v2; L[i] = v2;
  }
  // @End [pbTFTnYz]
  ll Q; cin >> Q;
  // @InpVec(Q, T) [WqMWi9UW]
  auto T = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; T[i] = v; }
  // @End [WqMWi9UW]
  ll LEAVE = 0;
  ll QUERY = 1;
  using ev_tp = tuple<ll, ll, ll>;
  vector<ev_tp> ev;
  REP(i, 0, N) ev.emplace_back(L[i], LEAVE, i);
  REP(i, 0, Q) ev.emplace_back(T[i], QUERY, i);
  ranges::sort(ev, greater<ev_tp>());
  vector<ll> ans(Q);
  ll hmax = 0;
  for (auto [t, kd, idx] : ev) {
    if (kd == LEAVE) {
      hmax = max(hmax, H[idx]);
    }else {
      ans[idx] = hmax;
    }
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

