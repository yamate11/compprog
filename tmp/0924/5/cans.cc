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
  vector<ll> C(10);
  REP(i, 1, 10) cin >> C[i];
  C[0] = 1e10;
  /*
  ll lo_num = -1, lo = 1e10;
  REP(i, 1, 10) {
    if (C[i] <= lo) {
      lo_num = i;
      lo = C[i];
    }
  }
  */
  ll lo = *min_element(ALL(C));
  ll keta = N / lo;
  ll paid = 0;
  REP(i, 0, keta) {
    REPrev(d, 9, 1) {
      if (paid + C[d] + lo * (keta - i - 1) <= N) {
        paid += C[d];
        cout << d;
        break;
      }
    }
  }
  cout << endl;

  return 0;
}

