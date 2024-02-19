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
  // @InpMVec(N - 1, ((U, dec=1), (V, dec=1))) [P9pC1lqu]
  auto U = vector(N - 1, ll());
  auto V = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) {
    ll v1; cin >> v1; v1 -= 1; U[i] = v1;
    ll v2; cin >> v2; v2 -= 1; V[i] = v2;
  }
  // @End [P9pC1lqu]
  vector<ll> deg(N);
  vector nbr(N, vector<ll>());
  REP(i, 0, N - 1) {
    deg[U[i]]++;
    deg[V[i]]++;
    nbr[U[i]].push_back(V[i]);
    nbr[V[i]].push_back(U[i]);
  }
  vector<ll> st;
  REP(i, 0, N) if (deg[i] == 1) st.push_back(i);
  vector<ll> ans;
  while (not st.empty()) {
    ll i = st.back(); st.pop_back();
    if (deg[i] != 1) continue;
    for (ll j : nbr[i]) {
      if (deg[j] == 0) continue;
      ans.push_back(deg[j]);
      for (ll k : nbr[j]) {
        assert(deg[k] > 0);
        if (deg[k] > 1) {
          assert(deg[k] == 2);
          for(ll m : nbr[k]) {
            if (m == j) continue;
            deg[m]--;
            if (deg[m] == 1) st.push_back(m);
          }
        }
        deg[k] = 0;
      }
      deg[j] = 0;
    }
  }
  sort(ALL(ans));
  REPOUT(i, 0, ssize(ans), ans[i], " ");

  return 0;
}

