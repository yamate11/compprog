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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 200;
  vector<ll> cnt(2*lim + 1);
  ll N; cin >> N;
  REP(i, 0, N) {
    ll a; cin >> a;
    cnt[lim + a]++;
  }
  ll s = 0;
  REP(i, 0, 2*lim + 1) REP(j, 0, 2*lim + 1) {
    s += (i - j) * (i - j) * cnt[i] * cnt[j];
  }
  cout << s / 2 << endl;

  return 0;
}

