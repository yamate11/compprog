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

  ll N, Q; cin >> N >> Q;
  // @InpVec(Q, X, dec=1) [6GGRLWG5]
  auto X = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; v -= 1; X[i] = v; }
  // @End [6GGRLWG5]

  vector<ll> B(Q);
  vector<ll> cnt(N);
  REP(q, 0, Q) {
    if (X[q] >= 0) {
      B[q] = X[q];
      cnt[X[q]]++;
    }else {
      ll i0 = -1;
      ll vmin = 1000;
      REP(i, 0, N) {
        if (cnt[i] < vmin) {
          i0 = i;
          vmin = cnt[i];
        }
      }
      B[q] = i0;
      cnt[i0]++;
    }
  }
  REPOUT(i, 0, Q, B[i] + 1, " ");
  

  return 0;
}

