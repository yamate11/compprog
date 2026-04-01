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

  ll N, L, R; cin >> N >> L >> R;
  string S; cin >> S;
  ll n_alph = 26;
  vector vec(n_alph, vector<ll>());
  REP(i, 0, N) {
    vec[S[i] - 'a'].push_back(i);
  }
  ll ans = 0;
  REP(d, 0, n_alph) {
    ll cur = 0;
    REP(j, 0, ssize(vec[d])) {
      auto it1 = ranges::lower_bound(vec[d], vec[d][j] + L);
      auto it2 = ranges::lower_bound(vec[d], vec[d][j] + R + 1);
      cur += it2 - it1;
    }
    ans += cur;
  }
  cout << ans << "\n";
  return 0;
}

