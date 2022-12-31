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
  string S; cin >> S;
  vector<set<char>> A(N + 1), B(N + 1);
  REP(i, N) {
    A[i + 1] = A[i];
    A[i + 1].insert(S[i]);
    B[N - 1 - i] = B[N - i];
    B[N - 1 - i].insert(S[i]);
  }
  ll ans = 0;
  REP(i, N) {
    vector<ll> s;
    set_intersection(ALL(A[i]), ALL(B[i]), back_inserter(s));
    ans = max(ans, SIZE(s));
  }
  cout << ans << endl;

  return 0;
}

