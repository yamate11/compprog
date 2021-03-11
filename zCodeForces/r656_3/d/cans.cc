#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n, string& s) -> ll {

    auto checkeq = [&](ll st, ll len, char c) -> ll {
      ll cnt = 0;
      for (ll i = st; i < st + len; i++) if (s.at(i) != c) cnt++;
      return cnt;
    };

    auto check = [&](auto rF, ll st, ll len, char c) -> ll {
      if (len == 1) {
	if (s.at(st) == c) return 0;
	else return 1;
      }
      ll half = len / 2;
      ll x1 = checkeq(st, half, c) + rF(rF, st + half, half, c+1);
      ll x2 = rF(rF, st, half, c+1) + checkeq(st + half, half, c);
      return min(x1, x2);
    };

    return check(check, 0, n, 'a');
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    string s; cin >> s;
    cout << solve(n, s) << endl;
  }

  return 0;
}

