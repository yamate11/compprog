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

  auto solve = [&]() -> void {
    ll n, k; cin >> n >> k;
    // @InpVec(n, A, type=u64) [ArujI8BM]
    auto A = vector(n, u64());
    for (int i = 0; i < n; i++) { u64 v; cin >> v; A[i] = v; }
    // @End [ArujI8BM]
    vector<u64> B;
    ll beau = 0;
    for (u64 a : A) {
      beau += popcount(a);
      REP(i, 0, 63) {
        if (not (a >> i & 1)) {
          u64 x = 1ULL << i;
          if (x > (u64)k) break;
          B.push_back(x);
        }
      }
    }
    sort(ALL(B));
    ll idx = 0;
    while (idx < ssize(B)) {
      if (B[idx] <= (u64)k) {
        beau++;
        k -= B[idx];
        idx++;
      }else {
        break;
      }
    }
    cout << beau << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

