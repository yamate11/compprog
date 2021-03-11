#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  string s; cin >> s;
  auto alph = [&](char c) -> bool {
    return ((('a' <= c) and (c <= 'z')) || (('A' <= c) and (c <= 'Z')));
  };

  ll cnt = 0;
  ll len = 0;
  ll maxlen = 0;
  bool inparen = false;
  for (ll i = 0; i <= n; i++) {
    if (i < n && alph(s[i])) {
      if (i == 0 || !alph(s[i - 1])) {
	if (inparen) cnt++;
      }
      len++;
    }else {
      if (!inparen) {
	maxlen = max(maxlen, len);
      }
      len = 0;
      if (i == n) {
      }else if (s[i] == '(') {
	inparen = true;
      }else if (s[i] == ')') {
	inparen = false;
      }else if (s[i] == '_') {
      }
    }
  }
  cout << maxlen << " " << cnt << endl;

  return 0;
}

