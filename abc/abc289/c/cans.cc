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

  ll N, M; cin >> N >> M;
  vector<ll> A(M);
  REP(i, 0, M) {
    ll c; cin >> c;
    ll x = 0;
    REP(j, 0, c) {
      ll t; cin >> t; t--;
      x |= (1LL << t);
    }
    A[i] = x;
  }
  ll ans = 0;
  ll mask = (1LL << N) - 1;
  REP(x, 1, 1 << M) {
    ll y = 0;
    REP(i, 0, M) {
      if (x >> i & 1) y |= A[i];
    }
    if ((y & mask) == mask) ans++;
  }
  cout << ans << endl;
  return 0;
}

