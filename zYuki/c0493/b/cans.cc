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
    ll N, K; cin >> N >> K;
    ll KK = K - 1;
    ll ans1, ans2, ans3, ans4;
    ans2 = KK / (72 * N) + 1;
    ll ss = KK % (72 * N);
    ll t1 = ss / (8 * N);
    ans3 = t1 < ans2 ? t1 : t1 + 1;
    ll a = ans2 < ans3 ? ans3 - 1 : ans3;
    ll b = 8 - a;
    ll z = ss % (8 * N);
    if (z < a * N) {
      ll p = z / a;
      ll q = z % a;
      ans1 = 3 + p;
      ans4 = ans2 <= q ? q + 1 : q;
    }else {
      ll z1 = z - (a * N);
      ll p = z1 / b;
      ll q = z1 % b;
      ans1 = 3 + (N - 1 - p);
      ans4 = ans3 + q + 1;
      if (ans2 > ans3 and ans4 >= ans2) ans4++;
    }
    cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << "\n";
  };

  ll T; cin >> T;
  REP(_t, 0, T) solve();

  return 0;
}

