#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll Q; cin >> Q;
  vector<string> before;
  vector<string> after;
  bool rev = false;
  for (ll i = 0; i < Q; i++) {
    ll t; cin >> t;
    if (t == 1) {
      rev = ! rev;
    }else {
      ll f;
      string c;
      cin >> f >> c;
      if (f == 1) {
	if (!rev) before.push_back(c);
	else {
	  reverse(c.begin(), c.end());
	  after.push_back(c);
	}
      }else {
	if (!rev) after.push_back(c);
	else {
	  reverse(c.begin(), c.end());
	  before.push_back(c);
	}
      }
    }
  }
  string res = "";
  for (ll i = before.size() - 1; i >= 0; i--) {
    res += before.at(i);
  }
  res += S;
  for (ll i = 0; i < (ll)after.size(); i++) {
    res += after.at(i);
  }
  if (rev) reverse(res.begin(), res.end());
  cout << res << endl;


  return 0;
}

