#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll T; cin >> T;
  for (ll _z = 0; _z < T; _z++) {
    string s; cin >> s;
    bool zero = false, one = false;
    for (ll i = 0; i < (ll)s.size(); i++) {
      if (s.at(i) == '0') zero = true;
      else one = true;
    }
    if (!zero || !one) {
      cout << s << endl;
    }else {
      for (ll i = 0; i < (ll)s.size(); i++) {
	cout << "01";
      }
      cout << endl;
    }
  }

  return 0;
}

