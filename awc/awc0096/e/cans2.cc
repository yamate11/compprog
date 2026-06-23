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

  ll big = 1LL << 60;
  ll N, Q; cin >> N >> Q;
  // @InpVec(N, H) [OM9F2sjo]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [OM9F2sjo]
  H.push_back(big);
  // @InpMVec(Q, ((L, dec=1), (R, dec=1))) [WyxQNu4H]
  auto L = vector(Q, ll());
  auto R = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 1; R[i] = v2;
  }
  // @End [WyxQNu4H]
  vector qids(N, vector<ll>());
  REP(i, 0, Q) qids[L[i]].push_back(i);
  vector<ll> ans(Q);

  vector<ll> st{N};
  REPrev(i, N - 1, 0) {
    while (true) {
      ll a = st.back();
      if (H[i] <= H[a]) break;
      st.pop_back();
    }
    st.push_back(i);
    for (ll q : qids[i]) {
      auto it = ranges::lower_bound(st, R[q], greater<ll>());
      ans[q] = st.end() - it;
    }
  }
  REPOUT(q, 0, Q, ans[q], "\n");


  return 0;
}

