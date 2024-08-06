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
  // @InpMVec(N, (L, R)) [WYdfUqgU]
  auto L = vector(N, ll());
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [WYdfUqgU]
  ll lo = 0, hi = 0;
  REP(i, 0, N) {
    lo += L[i];
    hi += R[i];
  }
  if (lo <= 0 and 0 <= hi) {
    cout << "Yes\n";
    vector<ll> ans(N);
    ll val = lo;
    REP(i, 0, N) {
      if (val < 0) {
        ll x = R[i] - L[i];
        if (val + x <= 0) {
          ans[i] = R[i];
          val += x;
        }else {
          ans[i] = L[i] - val;
          val = 0;
        }
      }else {
        ans[i] = L[i];
      }
    }
    REPOUT(i, 0, N, ans[i], " ");
  }else {
    cout << "No\n";
  }

  return 0;
}

