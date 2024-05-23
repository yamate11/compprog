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

  ll N, K; cin >> N >> K;
  // @InpVec(N, P, dec=1) [xGTCKWRu]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [xGTCKWRu]

  vector<ll> revP(N);
  REP(i, 0, N) revP[P[i]] = i;

  set<ll> ss;
  REP(i, 0, K) ss.insert(revP[i]);
  auto width = [&]() -> ll {
    return *prev(ss.end()) - *ss.begin();
  };
  ll ans = width();
  REP(i, K, N) {
    ss.erase(revP[i - K]);
    ss.insert(revP[i]);
    ans = min(ans, width());
  }
  cout << ans << endl;

  return 0;
}

