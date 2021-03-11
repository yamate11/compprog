#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n, string& s1, string& s2) -> ll {
    vector cvt(128, vector(128, int8_t(false)));
    for (ll i = 0; i < n; i++) {
      if (s1.at(i) > s2.at(i)) return -1;
      if (s1.at(i) < s2.at(i)) cvt.at(s1.at(i)).at(s2.at(i)) = true;
    }
    ll cnt = 0;
    for (char c = 'a'; c < 'a' + 20; c++) {
      auto findfirst = [&]() -> char {
	for (char d = c + 1; d < 'a' + 20; d++) {
	  if (cvt.at(c).at(d)) return d;
	}
	return -1;
      };
      char f = findfirst();
      if (f < 0) continue;
      cnt++;
      for (char d = f + 1; d < 'a' + 20; d++) {
	if (cvt.at(c).at(d)) cvt.at(f).at(d) = true;
      }
    }
    return cnt;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    cout << solve(n, s1, s2) << endl;
  }

  return 0;
}

