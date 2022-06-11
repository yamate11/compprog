#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
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
  vector<ll> A(N); 
  vector<ll> L(N + 1, -1LL), R(N + 1, -1LL);
  REP(i, N) {
    ll a; cin >> a;
    A[i] = a;
    if (L[a] < 0) L[a] = i;
    R[a] = i;
  }
  ll ans = 0;
  ll bnd = -1;
  REP(i, N) {
    ll a = A[i];
    if (i < bnd) {
      if (R[a] <= bnd) ans++;
      else bnd = R[a];
    }else if (i == bnd) {
    }else {
      if (R[a] == L[a]) {
      }else bnd = R[a];
    }
  }
  cout << ans << endl;


  return 0;
}

