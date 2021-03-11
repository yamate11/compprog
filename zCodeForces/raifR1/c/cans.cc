#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    string s; cin >> s;
    ll n = s.size();
    vector<char> st;
    for (ll i = 0; i < n; i++) {
      if (s[i] == 'A') {
	st.push_back('A');
      }else {
	if (st.size() == 0) {
	  st.push_back('B');
	}else {
	  st.resize(st.size() - 1);
	}
      }
    }
    cout << st.size() << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

