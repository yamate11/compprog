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
  vector<string> S(N);
  for (ll i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  string ans(N, 'a');
  for (ll i = 0; i < (N+1) / 2; i++) {
    ll j = N-1 - i;
    if (i == j) {
      ans.at(i) = S.at(i).at(0);
    }else {
      vector<bool> b1(128);
      for (ll k = 0; k < N; k++) b1.at(S.at(i).at(k)) = true;
      bool found = false;
      for (ll k = 0; k < N; k++) {
	if (b1.at(S.at(j).at(k))) {
	  found = true;
	  ans.at(i) = ans.at(j) = S.at(j).at(k);
	  break;
	}
      }
      if (!found) {
	cout << "-1\n";
	return 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

