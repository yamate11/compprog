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

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    string s; cin >> s;
    string t; cin >> t;
    vector<ll> erase;
    REP(i, N) {
      if (t[0] != s[i]) continue;
      REP(j, i) erase.push_back(j);
      ll ii = i + 1;
      bool ok = true;
      REP2(j, 1, M) {
        for (; ii < N and t[j] != s[ii]; ii++) erase.push_back(ii);
        if (ii == N) { ok = false; break; }
        ii++;
      }
      if (not ok) continue;
      for (; ii < N; ii++) erase.push_back(ii);
    }

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

