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

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [UklpGUPN]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [UklpGUPN]
  vector cnt(N + 1, 0LL);
  REP(i, 0, N) if (A[i] <= N) cnt[A[i]]++;
  set<ll> zeroes;
  REP(i, 0, N + 1) if (cnt[i] == 0) zeroes.insert(i);

  REP(_q, 0, Q) {
    ll i, x; cin >> i >> x; i--;
    if (A[i] <= N) {
      cnt[A[i]]--;
      if (cnt[A[i]] == 0) {
        zeroes.insert(A[i]);
      }
    }
    A[i] = x;
    if (x <= N) {
      if (cnt[x] == 0) {
        zeroes.erase(x);
      }
      cnt[x]++;
    }
    ll m = *zeroes.begin();
    cout << m << "\n";
  }

  return 0;
}

