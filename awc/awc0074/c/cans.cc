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

  ll N, M; cin >> N >> M;
  vector<ll> vec(N + 1, 0LL);
  REP(i, 0, M) {
    ll l, r; cin >> l >> r; l--;
    vec[l] = 1 - vec[l];
    vec[r] = 1 - vec[r];
  }
  ll ans = 0;
  ll cur = 0;
  REP(i, 0, N) {
    if (vec[i] == 1) cur = 1 - cur;
    ans += cur;
  }
  cout << ans << endl;
  return 0;
}

