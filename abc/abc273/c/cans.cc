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

  ll N; cin >> N;
  // @InpVec(N, A) [mbJK8txj]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [mbJK8txj]
  map<ll, ll> mp;
  REP(i, 0, N) mp[A[i]]++;
  vector<ll> K;
  for (auto [i, c] : mp) K.push_back(i);
  sort(ALL(K), greater<ll>());
  vector<ll> ans(N);
  REP(i, 0, SIZE(K)) ans[i] = mp[K[i]];
  REPOUT(i, 0, N, ans[i], "\n");
  
  return 0;
}

