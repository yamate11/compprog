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
  vector<ll> cnt(M);
  vector<vector<ll>> app(N);
  REP(i, 0, M) {
    ll k; cin >> k;
    cnt[i] = k;
    REP(j, 0, k) {
      ll a; cin >> a; a--;
      app[a].push_back(i);
    }
  }
  ll ans = 0;
  REP(i, 0, N) {
    ll b; cin >> b; b--;
    for (ll j : app[b]) {
      if (cnt[j] == 1) ans++;
      cnt[j]--;
    }
    cout << ans << "\n";
  }

  return 0;
}

