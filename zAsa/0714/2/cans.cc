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

  ll N; cin >> N;
  string S; cin >> S;
  ll ans = 0;
  REP(j, 0, N + 1) {
    vector<bool> s1(26);
    vector<bool> s2(26);
    REP(i, 0, j) s1[S[i] - 'a'] = true;
    REP(i, j, N) s2[S[i] - 'a'] = true;
    ll cur = 0;
    REP(i, 0, 26) if (s1[i] and s2[i]) cur++;
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}

