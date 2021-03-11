#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  string s; cin >> s;
  ll cost = 0;

  auto func = [&](ll rem) -> void {
    set<string> ss;

    auto func2 = [&](auto rF, string cur, string go, ll grem) -> void {
      if (grem == 0) {
	string cand = cur + go;
	if (ss.find(cand) != ss.end()) return;
	ss.insert(cand);
	cost += rem;
	k--;
	return;
      }
      ll glen = go.size();
      if (glen < grem) return;
      char c = go[0];
      ll i = 0;
      while (i < glen && go[i] == c) i++;
      string nextgo = go.substr(i, glen - i);
      for (ll j = 0; j <= min(grem, i); j++) {
	rF(rF, cur + go.substr(0, i - j), nextgo, grem - j);
	if (k == 0) return;
      }
    };

    func2(func2, "", s, rem);

  };

  for (ll i = 0; i <= n; i++) {
    func(i);
    if (k == 0) break;
  }
  if (k == 0) cout << cost << endl;
  else cout << -1 << endl;

  return 0;
}

