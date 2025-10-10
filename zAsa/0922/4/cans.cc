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
    ll N; cin >> N;
    string S; cin >> S;
    
    vector vec(N + 1, 0LL);
    vec[N] = 0;
    REPrev(i, N - 1, 0) {
      if (S[i] == '0') vec[i] = vec[i + 1] - 1;
      else             vec[i] = vec[i + 1] + 1;
    }
    vector W(N + 1, 0LL);
    W[N] = 0;
    REPrev(i, N - 1, 0) W[i] = min(vec[i], W[i + 1]);

    ll p = 0;
    REP(i, 0, N) if (S[i] == '0') p++;
    ll ans = N + 1;
    REP(i, 0, N) {
      ans = min(ans, p + W[i]);
      if (S[i] == '0') p--;
      else             p++;
    }
    return ans;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

