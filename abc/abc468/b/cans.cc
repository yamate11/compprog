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

  ll M, D; cin >> M >> D;
  string S; cin >> S;
  vector<bool> stat(M, false);
  REP(i, 0, M) {
    if (S[i] == 'G') {
      REP(d, -D, D + 1) {
        ll j = i + d;
        if (0 <= j and j < M) stat[j] = true;
      }
    }
  }
  ll ans = 0;
  REP(i, 0, M) if (not stat[i]) ans++;
  cout << ans << endl;

  return 0;
}

