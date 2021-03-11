#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<vector<ll>> brd(3, vector<ll>(3));
  vector<vector<bool>> marked(3, vector<bool>(3));
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 3; j++) {
      cin >> brd.at(i).at(j);
    }
  }
  ll N; cin >> N;
  for (ll k = 0; k < N; k++) {
    ll b; cin >> b;
    for (ll i = 0; i < 3; i++) {
      for (ll j = 0; j < 3; j++) {
	if (brd.at(i).at(j) == b) marked.at(i).at(j) = true;
      }
    }
  }

  for (ll i = 0; i < 3; i++) {
    ll ok = true;
    for (ll j = 0; j < 3; j++) {
      if (!marked.at(i).at(j)) {
	ok = false;
	break;
      }
    }
    if (ok) {
      cout << "Yes\n";
      return 0;
    }
  }
  for (ll i = 0; i < 3; i++) {
    ll ok = true;
    for (ll j = 0; j < 3; j++) {
      if (!marked.at(j).at(i)) {
	ok = false;
	break;
      }
    }
    if (ok) {
      cout << "Yes\n";
      return 0;
    }
  }
  {
    ll ok = true;
    for (ll j = 0; j < 3; j++) {
      if (!marked.at(j).at(j)) {
	ok = false;
	break;
      }
    }
    if (ok) {
      cout << "Yes\n";
      return 0;
    }
  }
  {
    ll ok = true;
    for (ll j = 0; j < 3; j++) {
      if (!marked.at(j).at(2-j)) {
	ok = false;
	break;
      }
    }
    if (ok) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

