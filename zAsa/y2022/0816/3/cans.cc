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

  ll N; cin >> N;
  ll lim = 1e5;
  vector<ll> cnt(lim + 1);
  ll tot = 0;
  REP(i, 0, N) {
    ll a; cin >> a;
    cnt[a]++;
    tot += a;
  }
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll b, c; cin >> b >> c;
    tot += (c - b) * cnt[b];
    cnt[c] += cnt[b];
    cnt[b] = 0;
    cout << tot << "\n";
  }

  return 0;
}

