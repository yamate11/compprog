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
  // @InpMVec(N, (W, D)) [mANwXCrB]
  auto W = vector(N, ll());
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; W[i] = v1;
    ll v2; cin >> v2; D[i] = v2;
  }
  // @End [mANwXCrB]

  vector<ll> ord(N);
  REP(i, 0, N) ord[i] = i;
  auto comp = [&](ll i, ll j) -> bool {
    if (D[j] >= W[i] + D[i] and D[i] < W[j] + D[j]) return true;
    if (D[j] < W[i] + D[i] and D[i] >= W[j] + D[j]) return false;
    ll a = min(D[i], D[j] - W[i]);
    ll b = min(D[j], D[i] - W[j]);
    if (a > b) return true;
    return false;
  };
  ranges::sort(ord, comp);
  ll big = 1e18;
  vector<ll> vec(N + 1, big);
  vec[0] = 0;
  REP(ii, 0, N) {
    ll i = ord[ii];
    
  }


  return 0;
}

