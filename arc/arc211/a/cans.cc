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

  auto solve = [&]() -> ll {
    vector<ll> A(10);
    REP(i, 1, 10) cin >> A[i];
    if (A[5] == 0) {
      ll k = accumulate(ALL(A), 0LL);
      if (A[1] >= 1 and A[9] >= 1 and k == A[1] + A[9]) return 1;
      if (A[2] >= 1 and A[8] >= 1 and k == A[2] + A[8]) return 1;
      if (A[3] >= 1 and A[7] >= 1 and k == A[3] + A[7]) return 1;
      if (A[4] >= 1 and A[6] >= 1 and k == A[4] + A[6]) return 1;
      return 0;
    }else if (A[5] == 1) {
      return 0;
    }else {
      ll k = accumulate(ALL(A), 0LL) - A[5];
      if (k <= A[5] - 1) return A[5] - 1 - k;
      else return 0;
    }
    
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

