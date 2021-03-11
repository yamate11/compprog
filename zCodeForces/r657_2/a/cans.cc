#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = []() -> void {
    ll n; cin >> n;
    string s; cin >> s;
    ll cnt = 0;
    for (ll i = 0; i <= n - 7; i++) {
      if (s.substr(i, 7) == "abacaba") cnt++;
    }
    if (cnt == 1) {
      for (ll j = 0; j < n; j++) {
	if (s.at(j) == '?') s.at(j) = 'x';
      }
      cout << "Yes\n" << s << "\n";
      return;
    }
    if (cnt >= 2) {
      cout << "No\n";
      return;
    }
    const string target = "abacaba";
    for (ll i = 0; i <= n - 7; i++) {
      auto check = [&]() -> bool {
	for (ll j = 0; j < 7; j++) {
	  if (s.at(i+j) != target.at(j) && s.at(i+j) != '?') return false;
	}
	if (i-4 >= 0 && s.substr(i-4, 4) == "abac") return false;
	if (i-6 >= 0 && s.substr(i-6, 6) == "abacab") return false;
	if (i+11 <= n && s.substr(i+7, 4) == "caba") return false;
	if (i+13 <= n && s.substr(i+7, 6) == "bacaba") return false;
	return true;
      };
      if (check()) {
	for (ll j = 0; j < n; j++) {
	  if (s.at(j) == '?') {
	    if (i <= j && j < i + 7) s.at(j) = target.at(j - i);
	    else                     s.at(j) = 'x';
	  }
	}
	cout << "Yes\n" << s << "\n";
	return;
      }
    }
    cout << "No\n";
    return;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

