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
  string pat = "ABXY";
  ll big = 10000;
  ll ans = big;
  REP(i, 0, 4) REP(j, 0, 4) REP(p, 0, 4) REP(q, 0, 4) {
    ll cnt = 0;
    REP(x, 0, N) {
      cnt++;
      if (x + 1 < N) {
        if (S[x] == pat[i] and S[x + 1] == pat[j]) {
          x++;
        }else if (S[x] == pat[p] and S[x + 1] == pat[q]) {
          x++;
        }
      }
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}

