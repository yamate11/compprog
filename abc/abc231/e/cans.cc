#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<map<ll, ll>> vmp(N);
  auto func = [&](auto rF, ll x, ll n) -> ll {
    auto it = vmp[n].find(x);
    if (it != vmp[n].end()) {
      return it->second;
    }
    ll p = x / A[n];
    ll q = x % A[n];
    if (q == 0) {
      vmp[n][x] = p;
      return p;
    }
    ll v1 = rF(rF, q, n - 1);
    ll cand1 = v1 + p;
    ll v2 = rF(rF, A[n] - q, n - 1);
    ll cand2 = v2 + p + 1;
    ll cand = min(cand1, cand2);
    vmp[n][x] = cand;
    return cand;
  };

  ll ans = func(func, X, N-1);
  cout << ans << endl;

  return 0;
}

