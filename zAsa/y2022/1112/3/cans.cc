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

  ll N, M; cin >> N >> M;
  vector<ll> rec(N);
  REP(i, 0, M) {
    ll a, b; cin >> a >> b; a--; b--;
    if (a == 0) rec[b]++;
    if (b == N - 1) rec[a]++;
  }
  REP(i, 0, N) {
    if (rec[i] == 2) {
      cout << "POSSIBLE\n";
      return 0;
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}

