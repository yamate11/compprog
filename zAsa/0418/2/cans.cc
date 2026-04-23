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
  // @InpVec(N, S, type=string) [kujXRyWx]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [kujXRyWx]
  map<string, ll> mp;
  REP(i, 0, N) mp[S[i]]++;
  ll vmax = 0;
  for (auto [s, n] : mp) {
    vmax = max(vmax, n);
  }
  vector<string> ans;
  for (auto [s, n] : mp) {
    if (n == vmax) ans.push_back(s);
  }
  ranges::sort(ans);
  REPOUT(i, 0, ssize(ans), ans[i], "\n");

  return 0;
}

