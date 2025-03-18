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
    ll N, X, K; cin >> N >> X >> K;
    string S; cin >> S;
    ll p = X;
    REP(i, 0, N) {
      if (S[i] == 'L') p--;
      else p++;
      K--;
      if (p == 0) break;
      if (K == 0) {
        cout << 0 << "\n";
        return;
      }
    }
    if (p != 0) {
      cout << 0 << "\n";
      return;
    }
    ll cnt = 1;
    auto f = [&]() -> ll {
      REP(i, 0, N) {
        if (S[i] == 'L') p--;
        else p++;
        if (p == 0) return i + 1;
      }
      return -1;
    };
    ll loop = f();
    if (loop < 0) {
      cout << 1 << "\n";
      return;
    }
    cnt += K / loop;
    cout << cnt << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

