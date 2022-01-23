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
  ll lim = 1e5;
  using sta = pair<ll, ll>;
  vector A(lim + 1, vector<sta>());
  REP(i, N) {
    ll d, s, t; cin >> d >> s >> t;
    A[d].emplace_back(s, t);
  }
  REP2(d, 1, lim) {
    if (A[d].size() <= 1) continue;
    sort(ALL(A[d]));
    REP(i, SIZE(A[d]) - 1) {
      auto [s1, t1] = A[d][i];
      auto [s2, t2] = A[d][i + 1];
      if (s2 < t1) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";

  return 0;
}

