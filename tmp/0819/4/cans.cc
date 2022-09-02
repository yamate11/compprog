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

  ll lim = 1e5;
  vector<ll> cnt(lim + 1);
  ll N, K; cin >> N >> K;
  REP(i, 0, N) {
    ll a, b; cin >> a >> b;
    cnt[a] += b;
  }
  ll s = 0;
  REP(i, 1, lim + 1) {
    s += cnt[i];
    if (K <= s) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

