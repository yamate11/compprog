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

  ll N; cin >> N;
  string S; cin >> S;
  
  auto enc = [&](ll p, ll q) -> ll { return (N + p) * 2 * N + (N + q); };
  map<ll, ll> cnt;
  ll p = 0, q = 0;
  ll ans = 0;
  cnt[enc(0, 0)] = 1;
  for (char c : S) {
    if (c == 'A') p++;
    else if (c == 'T') p--;
    else if (c == 'G') q++;
    else if (c == 'C') q--;
    else assert(0);
    ans += cnt[enc(p, q)]++;
  }
  cout << ans << endl;

  return 0;
}

