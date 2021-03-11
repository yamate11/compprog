#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  ll M = N % 2 == 0 ? 1 : 2;
  vector<vector<ll>> tbl(N, vector<ll>(M+1));
  for (ll i = 0; i < N; i++) {
    if (i == 0) {
      tbl.at(0).at(0) = A.at(0);
      tbl.at(0).at(1) = LLONG_MIN;
      if (M == 2) tbl.at(0).at(2) = LLONG_MIN;
    }else if (i == 1) {
      tbl.at(1).at(0) = LLONG_MIN;
      tbl.at(1).at(1) = A.at(1);
      if (M == 2) tbl.at(1).at(2) = LLONG_MIN;
    }else if (i == 2) {
      tbl.at(2).at(0) = A.at(0) + A.at(2);
      tbl.at(2).at(1) = LLONG_MIN;
      if (M == 2) {
	tbl.at(2).at(2) = A.at(2);
      }
    }else {
      tbl.at(i).at(0) = tbl.at(i-2).at(0) + A.at(i);
      tbl.at(i).at(1) = max(tbl.at(i-2).at(1) + A.at(i),
			    tbl.at(i-3).at(0) + A.at(i));
      if (M == 2) {
	ll xxx = i >= 4 ? tbl.at(i-4).at(0) : LLONG_MIN;
	tbl.at(i).at(2) = max(max(tbl.at(i-2).at(2) + A.at(i),
				  tbl.at(i-3).at(1) + A.at(i)),
			      xxx);
      }
    }
  }
  ll ans;
  if (M == 2) {
    ans = max(max(tbl.at(N-3).at(0),
		  tbl.at(N-2).at(1)),
	      tbl.at(N-1).at(2));
  }
  if (M == 1) {
    ans = max(tbl.at(N-1).at(1),
	      tbl.at(N-2).at(0));
  }
  cout << ans << endl;

    

  return 0;
}

