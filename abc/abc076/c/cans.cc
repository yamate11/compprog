#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

void solve() {
  string S, T; cin >> S >> T;
  ll nS = S.size();
  ll nT = T.size();
  auto chkI = [&](ll& res) -> bool {
    for (ll i = nS - nT; i >= 0; i--) {
      auto chkJ = [&]() -> bool {
	for (ll j = 0; j < nT; j++) {
	  char cs = S.at(i + j);
	  char ct = T.at(j);
	  if (cs == ct || cs == '?') continue;
	  return false;
	}
	return true;
      };
      if (chkJ()) {
	res = i;
	return true;
      }
    }
    return false;
  };
  ll st;
  if (!chkI(st)) {
    cout << "UNRESTORABLE\n";
    return;
  }
  for (ll i = 0; i < nS; i++) {
    if (st <= i && i < st + nT) cout << T.at(i - st);
    else if (S.at(i) == '?') cout << 'a';
    else cout << S.at(i);
  }
  cout << endl;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  solve();

  return 0;
}

