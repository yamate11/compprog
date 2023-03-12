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

  ll N; cin >> N;
  string S; cin >> S;
  string S1 = S.substr(0, N);
  string S2 = S.substr(N, N);
  reverse(ALL(S2));
  map<pair<string, string>, ll> cnt1, cnt2;
  REP(x, 0, 1LL << N) {
    string a, b, c, d;
    REP(i, 0, N) {
      if (x >> i & 1) {
        a += S1[i];
        c += S2[i];
      }else {
        b += S1[i];
        d += S2[i];
      }
    }
    cnt1[{a, b}]++;
    cnt2[{c, d}]++;
  }
  ll ans = 0;
  for (auto& [p1, n1] : cnt1) ans += n1 * cnt2[p1];
  cout << ans << endl;

  return 0;
}

