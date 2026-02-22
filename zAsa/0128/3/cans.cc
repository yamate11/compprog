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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [72cxYTxe]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [72cxYTxe]

  auto check = [&]() -> bool {
    vector<ll> S(N + 1);
    REP(i, 0, N) S[i + 1] = S[i] + A[i];
    ll status = 0;
    REP(i, 0, N + 1) {
      if (status == 0 and S[i] >= K) status = 1;
      else if (status == 1 and S[i] < K) return false;
    }
    cout << "Yes\n";
    REPOUT(i, 0, N, A[i], " ");
    return true;
  };


  ranges::sort(A);
  if (check()) return 0;
  ranges::reverse(A);
  if (check()) return 0;
  cout << "No\n";

  return 0;
}

