#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool match(string s, string t, ll i) {
  if (i + t.size() > s.size()) return false;
  for (ll j = 0; j < (ll)t.size(); j++) {
    if (s.at(i+j) == t.at(j) || t.at(j) == '.') continue;
    else return false;
  }
  return true;
}

bool ss_match(string s, string t) {
  for (ll i = 0; i + t.size() <= s.size(); i++) {
    if (match(s, t, i)) return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string chars = ".abcdefghijklmnopqrstuvwxyz";

  ll cnt = 0;
  string S; cin >> S;
  string t0 = "";
  for (char c1 : chars) {
    string t1 = t0 + c1;
    if (ss_match(S, t1))  cnt++;
    for (char c2 : chars) {
      string t2 = t1 + c2;
      if (ss_match(S, t2)) cnt++;
      for (char c3 : chars) {
	string t3 = t2 + c3;
	if (ss_match(S, t3)) cnt++;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}

