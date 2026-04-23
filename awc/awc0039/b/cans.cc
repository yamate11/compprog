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

  ll N, M, T; cin >> N >> M >> T;
  vector<ll> summark(N);
  vector<ll> num(N);
  REP(i, 0, M) {
    ll c, s; cin >> c >> s; c--;
    summark[c] += s;
    num[c]++;
  }
  ll ans = 0;
  REP(i, 0, N) {
    if (num[i] > 0 and num[i] * T > summark[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}

