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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, A, B; cin >> N >> M >> A >> B;
  ll t = N;
  REP(i, M) {
    if (t <= A) t += B;
    ll c; cin >> c;
    if (c > t) {
      cout << i + 1 << endl;
      return 0;
    }
    t -= c;
  }
  cout << "complete\n";
  

  return 0;
}

