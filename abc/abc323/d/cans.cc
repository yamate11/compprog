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

  ll N; cin >> N;
  // @InpMVec(N, (S, C)) [knrmsP21]
  auto S = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
  }
  // @End [knrmsP21]

  map<ll, ll> mp;

  // priority_queue<pll, vector<pll>, greater<pll>> pque;
  // REP(i, 0, N) pque.emplace(S[i], C[i]);
  REP(i, 0, N) mp[S[i]] = C[i];
  ll ans = 0;
  while (not mp.empty()) {
    auto it = mp.begin();
    auto [s, c] = *it;
    ans += c % 2;
    if (c >= 2) mp[s * 2] += c / 2;
    mp.erase(it);
  }
  cout << ans << endl;
  return 0;
}

