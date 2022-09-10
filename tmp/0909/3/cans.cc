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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector v(N, vector(26, 0LL));
  REP(i, 0, N) {
    string s; cin >> s;
    REP(j, 0, SIZE(s)) v[i][s[j] - 'a']  = 1;
  }

  ll ans = 0;
  REP(x, 0, 1LL << N) {
    ll ta = 0;
    if (__builtin_popcountll(x) < K) continue;
    REP(i, 0, 26) {
      ll cnt = 0;
      REP(t, 0, N) if ((x >> t & 1) and v[t][i]) cnt++;
      if (cnt == K) ta++;
    }
    ans = max(ans, ta);
  }
  cout << ans << endl;

  return 0;
}

