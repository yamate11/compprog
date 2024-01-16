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

  ll t, N; cin >> t >> N;

  vector<bool> rec(100 + t + 1, false);
  REP(i, 1, 101) rec[ (100 + t) * i / 100 ] = true;
  ll x = (N - 1) / t;
  ll y = (N - 1) % t;
  ll cnt = 0;
  REP(i, 1, 100 + t + 1) {
    if (not rec[i]) cnt++;
    if (cnt == y + 1) {
      cout << x * (100 + t) + i << endl;
      return 0;
    }
  }

  return 0;
}

