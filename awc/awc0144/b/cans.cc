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

  ll N, K, M; cin >> N >> K >> M;
  // @InpVec(N, S) [TBLANrEF]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [TBLANrEF]
  vector retr(N, false);
  REP(i, 0, M) {
    ll d; cin >> d; d--;
    retr[d] = true;
  }
  vector<pll> B;
  REP(i, 0, N) {
    if (not retr[i]) B.emplace_back(S[i], -i);
  }
  ranges::sort(B, greater<pll>());
  REP(i, 0, K) {
    if (B[i].second == 0) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}

