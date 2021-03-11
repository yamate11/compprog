#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<string> S(n);
  for (ll i = 0 ; i < n; i++) cin >> S[i];
  // vector<ll> len(n);
  // len[n-1] = (ll)S[n-1].size();
  for (ll i = n - 2; i >= 0; i--) {
    // len[i] = (ll)S[i].size();
    for (ll j = 0; j < (ll)S[i].size(); j++) {
      if (j >= (ll)S[i+1].size() || S[i][j] > S[i+1][j]) {
	S[i] = S[i].substr(0, j);
	break;
      }else if (S[i][j] < S[i+1][j]) {
	break;
      }
    }
  }
  for (ll i = 0; i < n; i++) {
    cout << S[i] << "\n";
  }

  return 0;
}

