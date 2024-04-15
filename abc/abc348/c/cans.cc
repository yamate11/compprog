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
  // @InpMVec(N, (A, C)) [XWEguS63]
  auto A = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
  }
  // @End [XWEguS63]
  map<ll, ll> mp;
  REP(i, 0, N) {
    auto it = mp.find(C[i]);
    if (it == mp.end()) {
      mp[C[i]] = A[i];
    }else if (it->second > A[i]) {
      mp[C[i]] = A[i];
    }
  }
  ll ans = 0;
  for (auto [c, a] : mp) {
    if (ans < a) ans = a;
  }
  cout << ans << endl;

  return 0;
}

