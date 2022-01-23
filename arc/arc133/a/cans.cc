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
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  ll c = -1;
  REP(i, N - 1) {
    if (A[i] > A[i + 1]) {
      c = A[i];
      break;
    }
  }
  if (c == -1) c = A[N - 1];
  vector<ll> ans;
  REP(i, N) {
    if (A[i] != c) ans.push_back(A[i]);
  }
  for (ll a : ans) cout << a << " ";
  cout << endl;


  return 0;
}

