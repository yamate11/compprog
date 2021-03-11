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
  string s; cin >> s;
  ll cnt = 0;

  for (char c = 'z'; c >= 'b'; c--) {

    while (true) {
      bool succ = false;
      ll m = s.size();

      auto rem = [&](ll i, ll sft) {
	if (0 <= i + sft && i + sft < m && s[i] == c && s[i + sft] == c - 1) {
	  for (ll j = i + 1; j < m; j++) s[j - 1] = s[j];
	  s.resize(m - 1);
	  cnt ++;
	  return true;
	}
	return false;
      };

      for (ll i = 0; i < m; i++) {
	if (rem(i, -1) || rem(i, 1)) {
	  succ = true;
	  break;
	}
      }
      if (!succ) break;
    }
  }
  cout << cnt << endl;

  return 0;
}

