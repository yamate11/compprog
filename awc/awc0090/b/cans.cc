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

  ll L, N, C; cin >> L >> N >> C;
  ll cur = C;
  // @InpMVec(N, (P, W)) [AZEfYStG]
  auto P = vector(N, ll());
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; W[i] = v2;
  }
  // @End [AZEfYStG]
  if (N == 0) {
    if (C < L) {
      cout << -1 << endl;
    }else {
      cout << C - L << endl;
    }
    return 0;
  }


  REP(i, 0, N + 1) {
    ll prev, now;
    if (i == 0) {
      prev = 0; now = P[i];
    }else if (i == N) {
      prev = P[N - 1]; now = L;
    }else {
      prev = P[i - 1]; now = P[i];
    }
    if (cur < now - prev) {
      cout << -1 << endl;
      return 0;
    }
    cur -= (now - prev);
    if (i == N) {
      cout << cur << endl;
      return 0;
    }
    if (i < N) cur += W[i];
    if (cur > C) cur = C;
  }

  return 0;
}

