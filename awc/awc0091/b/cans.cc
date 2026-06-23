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
  vector<ll> W;
  REP(i, 0, N) {
    ll c; cin >> c;
    vector<ll> V(c);
    REP(j, 0, c) {
      cin >> V[j];
    }
    ranges::sort(V);
    ll v = V[c / 2];
    if (v > 0) W.push_back(v);
  }
  ranges::sort(W, greater<ll>());
  ll ans = 0;
  REP(i, 0, min(K, (ll)(ssize(W)))) ans += W[i];
  cout << ans << endl;

  return 0;
}

