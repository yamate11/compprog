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

  ll N, W; cin >> N >> W;
  // @InpVec(N, A) [TywzJPDH]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [TywzJPDH]
  A.push_back(0);
  A.push_back(0);
  ll sz = SIZE(A);
  vector<bool> rec(W + 1);
  REP(i, 0, sz) REP(j, i + 1, sz) REP(k, j + 1, sz) {
    ll w = A[i] + A[j] + A[k];
    if (w <= W) rec[w] = true;
  }
  ll cnt = 0;
  REP(i, 1, W + 1) if (rec[i]) cnt++;
  cout << cnt << endl;

  return 0;
}

