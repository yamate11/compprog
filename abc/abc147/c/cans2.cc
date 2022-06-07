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
#include <boost/range/irange.hpp>

// @@ !! LIM()

bool subseteq(ll x, ll y) { return (x & y) == x; }

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> r_honest(N), r_unkind(N);
  REP(i, N) {
    ll a; cin >> a;
    REP(j, a) {
      ll x, y; cin >> x >> y; x--;
      if (y == 1)      r_honest[i] |= 1LL << x;
      else if (y == 0) r_unkind[i] |= 1LL << x;
    }
  }
  ll ans = 0;
  REP(honest, 1LL << N) {
    ll unkind = ~honest & ((1LL << N) - 1);
    if (none_of(ALL(boost::irange(0LL, N)), [&](ll i) -> bool {
      return (honest >> i & 1) and not (subseteq(r_honest[i], honest) and subseteq(r_unkind[i], unkind));
    })) ans = max(ans, ll(__builtin_popcountll(honest)));
  }
  cout << ans << endl;

  return 0;
}

