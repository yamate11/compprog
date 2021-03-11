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
  vector<string> ans(n);
  using sta = pair<int, int>;
  vector data(26, vector(26, vector(26, vector<sta>())));
  for (ll i = 0; i < n; i++) {
    string team, town; cin >> team >> town;
    data[team[0] - 'A'][team[1] - 'A'][team[2] - 'A']
      .emplace_back(town[0] - 'A', i);
  }
  auto mkstr = [&](ll c1, ll c2, ll c3) -> string {
    string s = "";
    s += (char)('A' + c1);
    s += (char)('A' + c2);
    s += (char)('A' + c3);
    return s;
  };
  for (ll i = 0; i < 26; i++) {
    for (ll j = 0; j < 26; j++) {
      bool ok = true;
      for (ll k = 0; k < 26; k++) {
	if (data[i][j][k].size() > 1) {
	  ok = false;
	  break;
	}
      }
      if (ok) {
	for (ll k = 0; k < 26; k++) {
	  if (data[i][j][k].size() == 1) {
	    auto [c, idx] = data[i][j][k][0];
	    ans[idx] = mkstr(i, j, k);
	  }
	}
      }else {
	vector<bool> seen(26);
	for (ll k = 0; k < 26; k++) {
	  for (auto [c, idx] : data[i][j][k]) {
	    if (seen[c]) {
	      cout << "NO\n";
	      return 0;
	    }else {
	      seen[c] = true;
	    }
	  }
	}
	for (ll k = 0; k < 26; k++) {
	  for (auto [c, idx] : data[i][j][k]) {
	    ans[idx] = mkstr(i, j, c);
	  }
	}
      }
    }
  }
  cout << "YES\n";
  for (ll i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }


  return 0;
}

