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

  ll sigma = 26;
  string X, Y; cin >> X >> Y;
  ll lenX = ssize(X), lenY = ssize(Y);
  vector pX(sigma, vector(lenX + 1, 0LL));
  vector pY(sigma, vector(lenY + 1, 0LL));
  REP(d, 0, sigma) REP(i, 0, lenX) pX[d][i + 1] = pX[d][i] + (X[i] - 'a' == d ? 1 : 0);
  REP(d, 0, sigma) REP(i, 0, lenY) pY[d][i + 1] = pY[d][i] + (Y[i] - 'a' == d ? 1 : 0);
  vector<ll> cX{1, 0};
  vector<ll> cY{0, 1};
  ll big = 1LL << 61;
  auto op_fib = [&](auto& Z) -> void {
    for (ll i = 2; true; i++) {
      ll a = Z[i - 1] + Z[i - 2];
      Z.push_back(a);
      if (big <= a) break;
    }
  };
  op_fib(cX);
  op_fib(cY);
  ll z = min(ssize(cX), ssize(cY));
  vector<ll> szs;
  REP(i, 0, z) {
    if (cX[i] >= big / lenX or cY[i] >= big / lenY) {
      szs.push_back(big);
      break;
    }
    ll a = lenX * cX[i] + lenY * cY[i];
    szs.push_back(a);
    if (a >= big) break;
  }
  vector nX(sigma, 0LL);
  vector nY(sigma, 0LL);
  for (char c : X) nX[c - 'a']++;
  for (char c : Y) nY[c - 'a']++;
  auto f = [&](auto rF, ll t, ll k, char c) -> ll {
    ll d = c - 'a';
    if (k == 0) return 0;
    if (t == 0) return pX[d][k];
    if (k <= lenY) return pY[d][k];
    ll i0 = lower_bound(szs.begin() + 1, szs.end(), k) - szs.begin();
    assert(i0 >= 2);
    ll val1 = nX[d] * cX[i0 - 1] + nY[d] * cY[i0 - 1];
    ll val2 = rF(rF, i0  - 2, k - szs[i0 - 1], c);
    return val1 + val2;
  };
  ll t0 = 1e18;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r;
    char c; cin >> c;
    cout << f(f, t0, r, c) - f(f, t0, l - 1, c) << "\n";
  }

  return 0;
}

