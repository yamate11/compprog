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
  // @InpVec(N, P, dec=1) [zgFzembU]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [zgFzembU]
  vector revP(N, 0LL);
  REP(i, 0, N) revP[P[i]] = i;

  vector<ll> lefts;
  REPrev(i, N - 1, 0) lefts.push_back(i);

  vector<pll> ans;
  while(not lefts.empty()) {
    ll x = lefts.back();
    ll i = revP[x];
    if (i + K >= N) {
      lefts.pop_back();
    }else {
      ll j0 = -1, y0 = -1;
      REP(j, i + K, N) {
        if (x > P[j] and P[j] > y0) {
          j0 = j;
          y0 = P[j0];
        }
      }
      if (j0 < 0) {
        lefts.pop_back();
      }else {
        ans.emplace_back(i, j0);
        P[i] = y0;
        P[j0] = x;
        revP[y0] = i;
        revP[x] = j0;
        lefts.push_back(y0);
      }
    }
  }
  cout << ssize(ans) << endl;
  for (auto [l, r] : ans) {
    cout << l + 1 << " " << r + 1 << "\n";
  }

  return 0;

}

