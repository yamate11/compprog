#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  string S; cin >> S;
  using Vec = vector<ll>;
  map<Vec, ll> tbl;
  Vec cur(26);
  for (ll i = 0; i < N; i++) {
    if (i >= K) cur.at(S.at(i-K) - 'a')--;
    cur.at(S.at(i) - 'a')++;
    if (i >= K-1) {
      auto it = tbl.find(cur);
      if (it != tbl.end()) {
	if (i - it->second >= K) {
	  cout << "YES\n";
	  return 0;
	}
      }else {
	tbl[cur] = i;
      }
    }
  }
  cout << "NO\n";
  return 0;
}

