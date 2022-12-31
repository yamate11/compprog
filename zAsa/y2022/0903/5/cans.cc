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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [vTTNZmgb]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [vTTNZmgb]
  ll H = 60;
  vector<ll> pt0(H), pt1(H);
  REP(i, 0, H) {
    REP(j, 0, N) pt0[i] += (A[j] & (1LL << i));
    pt1[i] = (1LL << i) * N - pt0[i];
  }
  vector<ll> tight(H), loose(H);
  REP(i, 0, H) {
    loose[i] = max(pt0[i], pt1[i]) + (i == 0 ? 0 : loose[i - 1]);
    if (K >> i & 1) {
      ll x = pt1[i] + (i == 0 ? 0 : tight[i - 1]);
      ll y = pt0[i] + (i == 0 ? 0 : loose[i - 1]);
      tight[i] = max(x, y);
    }else {
      tight[i] = pt0[i] + (i == 0 ? 0 : tight[i - 1]);
    }
  }
  cout << tight[H - 1] << endl;

  return 0;
}

