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
    ll N, M; cin >> N >> M;
    // @InpVec(N, A) [DIqmdHwk]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [DIqmdHwk]

    string ans;
    auto f = [&](auto rF, ll i, ll carry) -> ll {
      ll x = A[i] + carry;
      if (i == N - 1) {
        ll a = x / M;
        ll b = x % M;
        if (a > 0) ans = to_string(a);
        return min(b, carry);
      }else {
        ll y = x / 10;
        ll z = x % 10;
        ll rem = rF(rF, i + 1, y);
        z += rem * 10;
        ll a = z / M;
        ll b = z % M;
        assert(a <= 9);
        if (a > 0 or not ans.empty()) {
          ans.push_back((char)('0' + a));
        }
        return min(b, carry);
      }
    };
    f(f, 0, 0);
    if (ans.empty()) {
      ans.push_back('0');
    }
    cout << ans << "\n";
  };


  ll T; cin >> T;
  REP(_t, 0, T) solve();

  return 0;
}

