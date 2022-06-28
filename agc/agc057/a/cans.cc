#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

auto func(ll x) {
  vector<ll> digits;
  vector<ll> pows;
  ll p = 1;
  while (x > 0) {
    digits.push_back(x % 10);
    pows.push_back(p);
    x /= 10;
    p *= 10;
  }
  return make_pair(move(digits), move(pows));
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll L, R; cin >> L >> R;
    auto [digits, pows] = func(R);
    ll k = SIZE(digits) - 1;
    if (k == 0) return R + 1 - L;
    ll lim = -1;
    if (digits[k] >= 2) {
      lim = pows[k];
    }else if (R >= (pows[k] * 10 - 1) / 9) {
      lim = R - pows[k] + 1;
    }else {
      lim = R / 10 + 1;
    }
    return R + 1 - max(lim, L);
  };

  ll T; cin >> T;
  REP(_t, T) cout << solve() << "\n";

  return 0;
}

