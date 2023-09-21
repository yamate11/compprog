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

  string S; cin >> S;
  ll N = SIZE(S);

  auto f = [&](ll i, ll j) -> bool {
    REP(k, 0, j - i + 1) {
      ll i1 = i + k;
      ll j1 = j - k;
      if (S[i1] != S[j1]) return false;
    }
    return true;
  };

  ll ans = 1;
  REP(i, 0, N) REP(j, i, N) {
    bool v = f(i, j);
    if (v) {
      ans = max(ans, j - i + 1);
    }
  }
  cout << ans << endl;

  return 0;
}

