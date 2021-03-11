#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using Vec1 = vector<ll>;
  using Vec2 = vector<Vec1>;
  using Vec3 = vector<Vec2>;

  string S; cin >> S;
  ll M = S.size();
  ll K; cin >> K;
  Vec3 tbl(M+1, Vec2(K+1, Vec1(2)));
  tbl.at(0).at(0).at(0) = 1;
  for (ll i = 0; i < M; i++) {
    for (ll k = 0; k <= K; k++) {
      tbl.at(i+1).at(k).at(1)   +=     tbl.at(i).at(k).at(1);
      if (k < K) {
	tbl.at(i+1).at(k+1).at(1) += 9 * tbl.at(i).at(k).at(1);
      }
    }
    ll d = S.at(i) - '0';
    if (d == 0) {
      for (ll k = 0; k <= K; k++) { 
	tbl.at(i+1).at(k).at(0) += tbl.at(i).at(k).at(0);
      }
    }else {
      for (ll k = 0; k <= K; k++) { 
	tbl.at(i+1).at(k  ).at(1) +=           tbl.at(i).at(k).at(0);
	if (k < K) {
	  tbl.at(i+1).at(k+1).at(1) += (d - 1) * tbl.at(i).at(k).at(0);
	  tbl.at(i+1).at(k+1).at(0) +=           tbl.at(i).at(k).at(0);
	}
      }
    }
  }
  ll ans = tbl.at(M).at(K).at(1) + tbl.at(M).at(K).at(0);
  cout << ans << endl;

  return 0;
}

