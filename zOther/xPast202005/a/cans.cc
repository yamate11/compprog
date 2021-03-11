#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

string upp(string s) {
  string t;
  for (ll i = 0; i < (ll)s.size(); i++) {
    t += toupper(s.at(i));
  }
  return t;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s, t; cin >> s >> t;
  if (s == t) {
    cout << "same" << endl;
  }else if (upp(s) == upp(t)) {
    cout << "case-insensitive" << endl;
  }else {
    cout << "different" << endl;
  }

  return 0;
}

