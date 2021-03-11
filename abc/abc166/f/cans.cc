#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

string abc("ABC");

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> t(3);
  ll N; cin >> N >> t.at(0) >> t.at(1) >> t.at(2);
  vector<string> s(N);
  for (ll i = 0; i < N; i++) cin >> s.at(i);
  ll tsum = t.at(0) + t.at(1) + t.at(2);
  if (tsum == 0) {
    cout << "No\n";
    return 0;
  }
  vector<char> hand;

  auto take = [&](ll p, ll q) {
    hand.push_back(abc.at(p));
    t.at(p)++;
    t.at(q)--;
  };

  for (ll i = 0; i < N; i++) {
    string cur = s.at(i);
    ll x, y;
    if (cur == "AB") { x = 0; y = 1; }
    else if (cur == "AC") { x = 0; y = 2; }
    else if (cur == "BC") { x = 1; y = 2; }
    else assert(false);
    if (t.at(x) == 0) {
      if (t.at(y) == 0) {
	cout << "No\n";
	return 0;
      }
      take(x, y);
    }else if (t.at(y) == 0) {
      take(y, x);
    }else if (t.at(x) >= 2) {
      take(y, x);
    }else if (t.at(y) >= 2) {
      take(x, y);
    }else { // both one
      if (i+1 == N) {
	take(x, y);
      }else if (s.at(i+1) == cur) {
	take(x, y);
      }else {
	ll p, q;
	if (s.at(i+1) == "AB") { p = 0; q = 1; }
	else if (s.at(i+1) == "AC") { p = 0; q = 2; }
	else if (s.at(i+1) == "BC") { p = 1; q = 2; }
	else assert(false);
	if (x == p || x == q) {
	  take(x, y);
	}else {
	  take(y, x);
	}
      }
    }
    
  }
  cout << "Yes\n";
  for (ll i = 0; i < N; i++) {
    cout << hand.at(i) << "\n";
  }
  

  return 0;
}

