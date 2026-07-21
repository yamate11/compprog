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

  ll N, S, K; cin >> N >> S >> K; S--;
  // @InpVec(N, A) [2F5GvQiS]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [2F5GvQiS]
  vector<ll> SA(N + 1, 0LL);
  REP(i, 0, N) SA[i + 1] = SA[i] + A[i];
  ll ans = 0;
  auto f = [&](ll i) -> ll {
    if (i < S) {
      if (K <= S - i) return SA[S + 1] - SA[S - K];
      else if (K <= 2 * (S - i)) return SA[S + 1] - SA[i];
      else if (K <= 2 * (S - i) + (N - 1 - S)) return SA[S + K - (2 * (S - i)) + 1] - SA[i];
      else return SA[N] - SA[i];
    }else if (i > S) {
      if (K <= i - S) return SA[S + K + 1] - SA[S];
      else if (K <= 2 * (i - S)) return SA[i + 1] - SA[S];
      else if (K <= i - S + i) return SA[i + 1] - SA[2*i - S - K];
      else return SA[i + 1];
    }else if (i == S) return 0;
    else assert(0);

  };
  REP(i, 0, N) ans = max(ans, f(i));
  cout << ans << "\n";

  return 0;
}

