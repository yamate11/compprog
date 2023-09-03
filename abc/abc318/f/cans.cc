#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  // @InpVec(N, X) [WeSyhc8O]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [WeSyhc8O]
  // @InpVec(N, L) [JIEmdsfW]
  auto L = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; L[i] = v; }
  // @End [JIEmdsfW]

  vector<ll> P;
  P.push_back(X[N - 1] - L[N - 1] - 10);
  P.push_back(X[0] + L[N - 1] + 10);
  REP(i, 0, N) REP(j, 0, N) {
    ll x = X[i] + X[j];
    if (x % 2 == 0) P.push_back(x / 2 + 1);
    else P.push_back((x + 1) / 2);
  }
  REP(i, 0, N) P.push_back(X[i]);
  sort(ALL(P));
  P.erase(unique(ALL(P)), P.end());
  ll ans = 0;
  REP(_p, 0, SIZE(P) - 1) {
    ll p0 = P[_p];
    ll p1 = P[_p + 1];
    vector<ll> ord(N);
    REP(i, 0, N) ord[i] = i;
    sort(ALL(ord), [&](ll i, ll j) -> bool { return abs(p0 - X[i]) < abs(p0 - X[j]); });
    ll z0 = p0, z1 = p1;
    auto intersect = [&](ll q, ll r) -> void {
      z0 = max(z0, q);
      z1 = min(z1, r);
      if (z0 > z1) z0 = z1;
    };
    REP(i, 0, N) {
      ll l = L[i];
      ll j = ord[i];
      ll x = X[j];
      if (x <= p0) {
        if (p1 - x <= l) intersect(p0, p1);
        else if (p0 - x > l) intersect(p0, p0);
        else intersect(p0, x + l + 1);
      }else {
        if (x - p1 > l) intersect(p1, p1);
        else if (x - p0 <= l) intersect(p0, p1);
        else intersect(x - l, p1);
      }
    }
    ans += z1 - z0;
  }
  cout << ans << endl;
  return 0;
}

