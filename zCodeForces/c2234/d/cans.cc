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
    ll N, k; cin >> N >> k;
    string sa, sb; cin >> sa >> sb;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    REP(i, 0, N) {
      A[i] = sa[i] - '0';
      B[i] = sb[i] - '0';
      C[i] = A[i] ^ B[i];
    }
    auto f = [&](const auto& vec) -> ll {
      ll x = 0, y = 0;
      REP(i, 0, N) {
        if (vec[i] == 0) x++;
        else y++;
      }
      return x * y;
    };
    ll za = f(A);
    ll zb = f(B);
    ll zc = f(C);
    ll K = (1LL << k) + 1;
    ll p = K / 3;
    ll ans;
    if (k % 2 == 0) {
      ans = (za + zb + zc) * p + za + zb;
    }else {
      ans = (za + zb + zc) * p;
    }
    cout << ans << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

