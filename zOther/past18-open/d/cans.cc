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
  vector score(N, 0LL);
  vector hitby(N, -1LL);
  REP(m, 0, M) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x, y; cin >> x >> y; x--; y--;
      hitby[y] = x;
    }else if (tp == 2) {
      ll z; cin >> z; z--;
      score[z]--;
      if (hitby[z] >= 0) score[hitby[z]]++;
      hitby[z] = -1;
    }
  }
  REPOUT(i, 0, N, score[i], " ");

  return 0;
}

