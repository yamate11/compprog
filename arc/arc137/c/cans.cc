#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> string {
    ll N; cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    if (A[N - 1] == N - 1) return "Bob";
    if (A[N - 2] <= N - 1) return "Alice";
    if (A[N - 2] + 1 == A[N - 1] and (A[N - 2] - N) % 2 == 0) return "Bob";
    return "Alice";
  };
  cout << solve() << endl;
  return 0;
}

