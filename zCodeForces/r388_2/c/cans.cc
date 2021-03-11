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
  ll sz = n * 2;
  vector<char> s(sz, (char)0);
  string tmp; cin >> tmp;
  for (ll i = 0; i < n; i++) s[i] = tmp[i];

  ll r = 0;
  ll d = 0;
  ll j = n;
  for (ll i = 0; i < sz; i++) {
    if (s[i] == 0) continue;
    if (s[i] == 'R') {
      if (d <= i) d = i + 1;
      for (; d < sz && s[d] != 'D'; d++);
      if (d == sz) {
	cout << 'R' << endl;
	return 0;
      }
      s[d] = (char)0;
      d++;
      s[j++] = 'R';
    }else if (s[i] == 'D') {
      if (r <= i) r = i + 1;
      for (; r < sz && s[r] != 'R'; r++);
      if (r == sz) {
	cout << 'D' << endl;
	return 0;
      }
      s[r] = (char)0;
      r++;
      s[j++] = 'D';
    }else assert(0);
  }
  

  return 0;
}

