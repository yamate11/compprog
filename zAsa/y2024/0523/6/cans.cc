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

  ll R, C, K; cin >> R >> C >> K;
  ll N; cin >> N;
  // @InpMVec(N, ((RR, dec=1), (CC, dec=1))) [qfQtolgA]
  auto RR = vector(N, ll());
  auto CC = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; RR[i] = v1;
    ll v2; cin >> v2; v2 -= 1; CC[i] = v2;
  }
  // @End [qfQtolgA]

  vector vR(R, 0LL);
  vector vC(C, 0LL);
  REP(i, 0, N) {
    vR[RR[i]]++;
    vC[CC[i]]++;
  }
  
  vector wR(N + 1, 0LL);
  vector wC(N + 1, 0LL);

  REP(i, 0, R) {
    wR[vR[i]]++;
  }
  REP(i, 0, C) {
    wC[vC[i]]++;
  }
  
  vector<pll> uR, uC;
  REP(i, 0, N + 1) {
    if (wR[i] > 0) uR.emplace_back(i, wR[i]);
    if (wC[i] > 0) uC.emplace_back(i, wC[i]);
  }

  ll ans = 0;
  REP(i, 0, N) {
    ll x = vR[RR[i]] + vC[CC[i]];
    if (x == K + 1) ans++;
    else if (x == K) ans--;
  }

  ll p = 0;
  REPrev(q, ssize(uC) - 1, 0) {
    auto [m2, n2] = uC[q];
    while (p < ssize(uR)) {
      auto [m1, n1] = uR[p];
      if (m1 + m2 > K) break;
      if (m1 + m2 == K) {
        ans += n1 * n2;
        break;
      }
      p++;
    }
  }
  cout << ans << endl;

  return 0;
}

