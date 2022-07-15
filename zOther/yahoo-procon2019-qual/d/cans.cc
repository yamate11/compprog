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

  ll L; cin >> L;
  vector<ll> A(L);
  REP(i, L) {
    ll a; cin >> a;
    A[i] = 1 - a % 2;
  }
  ll tot = 0; REP(i, L) tot += A[i];
  vector<ll> B(L + 1), C(L + 1), D(L + 1);
  REP(i, L) {
    B[i + 1] = B[i] + (A[i] == 0 ? 1 : -1);
    C[L - i - 1] = C[L - i] + (A[L - 1 - i] == 0 ? 1 : -1);
  }
  REP(i, L) {
    D[i + 1] = min(D[i], B[i + 1]);
  }
  ll vmin = 0;
  REP(i, L + 1) vmin = min(vmin, D[i] + C[i]);
  cout << tot + vmin << endl;

  return 0;
}

