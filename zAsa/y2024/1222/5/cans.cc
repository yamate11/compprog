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
  // @InpVec(N, A, type=u64) [IBndl1k7]
  auto A = vector(N, u64());
  for (int i = 0; i < N; i++) { u64 v; cin >> v; A[i] = v; }
  // @End [IBndl1k7]

  map<u64, ll, greater<u64>> mp;
  ll ans = 0;
  REP(i, 0, N) mp[A[i]]++;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    auto [a, n] = *it;
    if (has_single_bit(a)) ans += n / 2;
    else {
      u64 x = bit_ceil(a);
      u64 b = x - a;
      auto it2 = mp.find(b);
      if (it2 != mp.end()) {
        ll m = min(n, it2->second);
        ans += m;
        it2->second -= m;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

