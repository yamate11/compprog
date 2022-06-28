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

  map<string, ll> mp;
  ll N; cin >> N;
  REP(i, N) {
    string s; cin >> s;
    mp[s]++;
  }
  ll M; cin >> M;
  REP(i, M) {
    string s; cin >> s;
    mp[s]--;
  }
  ll ans = 0;
  for (auto [s, v] : mp) {
    ans = max(ans, v);
  }
  cout << ans << endl;

  return 0;
}

