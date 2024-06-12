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

  ll L; cin >> L;
  // @InpVec(L, B) [nUcKGMju]
  auto B = vector(L, ll());
  for (int i = 0; i < L; i++) { ll v; cin >> v; B[i] = v; }
  // @End [nUcKGMju]

  vector<ll> ans(L);
  REPrev(k, 30, 0) {
    auto check = [&](ll x) -> pair<bool, vector<ll>> {
      vector<ll> vec(L);
      vec[0] = x;
      REP(i, 1, L) vec[i] = vec[i - 1] ^ (B[i - 1] >> k & 1);
      return make_pair((vec[L - 1] ^ (B[L - 1] >> k & 1)) == vec[0], move(vec));
    };
    auto f = [&]() -> bool {
      REP(x, 0, 2) {
        auto [b0, vec0] = check(x);
        if (b0) {
          REP(i, 0, L) ans[i] |= vec0[i] << k;
          return true;
        }
      }
      return false;
    };
    if (not f()) {
      cout << -1 << endl;
      return 0;
    }
  }
  REPOUT(i, 0, L, ans[i], "\n");

  return 0;
}

