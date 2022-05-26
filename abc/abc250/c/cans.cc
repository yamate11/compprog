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

  ll N, Q; cin >> N >> Q;
  vector<ll> A(N), pos(N);
  REP(i, N) {
    A[i] = i;
    pos[i] = i;
  }
  REP(q, Q) {
    ll x; cin >> x; x--;
    ll p = pos[x];
    if (p == N - 1) {
      swap(A[N - 2], A[N - 1]);
      pos[x] = N - 2;
      pos[A[N - 1]] = N - 1;
    }else {
      swap(A[p], A[p + 1]);
      pos[A[p]] = p;
      pos[A[p + 1]] = p + 1;
    }
  }
  REP(i, N) cout << A[i] + 1 << " ";
  cout << "\n";

  return 0;
}

