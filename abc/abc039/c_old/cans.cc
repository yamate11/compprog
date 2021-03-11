#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<string> name({"Do", "", "Re", "", "Mi",
	"Fa", "", "So", "", "La", "", "Si"});
  string arr0 = "WBWBWWBWBWBW";
  string arr = arr0 + arr0 + arr0 + arr0;
  string S; cin >> S;
  for (ll i = 0; i < (ll)name.size(); i++) {
    bool ok = true;
    for (ll j = 0; j < 20; j++) {
      if (arr.at(i+j) != S.at(j)) {
	ok = false;
	break;
      }
    }
    if (ok) {
      cout << name.at(i) << endl;
      return 0;
    }
  }

  return 0;
}

