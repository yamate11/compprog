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

  ll N, K, Q; cin >> N >> K >> Q;
  // @InpVec(Q, A, dec=1) [5mwVs5G1]
  auto A = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [5mwVs5G1]

  vector<ll> cnt(N);
  REP(i, 0, Q) cnt[A[i]]++;
  REP(i, 0, N) {
    if (K + cnt[i] - Q > 0) {
      cout << "Yes\n";
    }else {
      cout << "No\n";
    }

  }

  return 0;
}

