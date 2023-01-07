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

  ll N, K; cin >> N >> K;
  // @InpVec(N, C) [2kRLUcMn]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [2kRLUcMn]
  // @InpVec(N, P) [cMeohCKJ]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [cMeohCKJ]
  map<ll, ll> mp;
  REP(i, 0, N) {
    if (mp.find(C[i]) == mp.end()) mp[C[i]] = P[i];
    else mp[C[i]] = min(mp[C[i]], P[i]);
  }
  multiset<ll> ps;
  for (auto [c, p]: mp) ps.insert(p);
  ll cnt = 0;
  ll sum = 0;
  for (ll p : ps) {
    sum += p;
    cnt++;
    if (cnt == K) {
      cout << sum << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

