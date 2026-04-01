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
  vector<ll> vec;
  REP(j, 0, N) {
    ll C; cin >> C;
    ll M; cin >> M;
    // @InpVec(M, P) [QHX2zZ8Z]
    auto P = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; P[i] = v; }
    // @End [QHX2zZ8Z]
    ll x = accumulate(ALL(P), 0LL);
    if (x - C > 0) vec.push_back(x - C);
  }
  ranges::sort(vec, greater<ll>());
  ll t = min(K, (ll)ssize(vec));
  ll ans = 0;
  REP(i, 0, t) ans += vec[i];
  cout << ans << endl;


  return 0;
}

