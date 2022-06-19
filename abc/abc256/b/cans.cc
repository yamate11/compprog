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

  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll P = 0;
  vector<ll> B(4);
  REP(i, N) {
    ll a = A[i];
    REP2R(j, 3, 0) {
      if (B[j]) {
        B[j] = 0;
        if (j + a >= 4) P++;
        else B[j + a] = 1;
      }
    }
    if (a == 4) P++;
    else B[a] = 1;
  }
  cout << P << endl;

  return 0;
}

