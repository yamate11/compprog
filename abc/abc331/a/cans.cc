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

  ll M, D; cin >> M >> D;
  ll y, m, d; cin >> y >> m >> d;
  ll ay = y;
  ll am = m;
  ll ad = d;
  if (d < D) {
    ad = d + 1;
  }else {
    ad = 1;
    if (m < M) {
      am = m + 1;
    }else {
      am = 1;
      ay = y + 1;
    }
  }
  cout << ay << " " << am << " " << ad << endl;

  return 0;
}

