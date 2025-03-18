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

  ll N, M; cin >> N >> M;
  // @InpVec(N, X) [2Aor8rxC]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [2Aor8rxC]

  ll lim = 1e5 + 1;
  vector<ll> C(lim);
  vector<deque<ll>> D(M);
  REP(i, 0, N) C[X[i]]++;
  REP(i, 0, lim) {
    ll k = i % M;
    ll n = C[i];
    ll a = n / 2;
    ll b = n % 2;
    REP(j, 0, a) {
      D[k].push_front(i);
      D[k].push_front(i);
    }
    if (b != 0) D[k].push_back(i);
  }
  ll ans = 0;
  REP(i, 0, M) {
    ll j = M - i;
    if (i == 0 or i == j) ans += ssize(D[i]) / 2;
    else if (i < j) {
      auto v1 = D[i];
      auto v2 = D[j];
      if (ssize(v1) < ssize(v2)) swap(v1, v2);
      ll s1 = ssize(v1);
      ll s2 = ssize(v2);
      ll r = s1 - s2;
      ans += s2;
      REP(p, 0, r) {
        if (p % 2 == 0 and p + 1 < r and v1[p] == v1[p + 1]) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

