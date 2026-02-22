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
  vector<string> v(3);
  REP(i, 0, 3) cin >> v[i];
  ll ans = 0;
  REP(i, 0, N) {
    bool b1 = v[0][i] == v[1][i];
    bool b2 = v[1][i] == v[2][i];
    bool b3 = v[2][i] == v[0][i];
    if (b1 and b2) ;
    else if (b1) ans++;
    else if (b2) ans++;
    else if (b3) ans++;
    else ans += 2;
  }
  cout << ans << endl;

  return 0;
}

