#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if DEBUG
  ll lim = 2;
#else
  ll lim = 26;
#endif

  string s; cin >> s;
  ll n = s.size();
  if (n < lim) {
    cout << -1 << endl;
    return 0;
  }

  ll dup = 0;
  vector<ll> cnt(128);
  ll i = 0;
  for ( ; i < n; i++) {
    if (i >= lim && dup == 0) break;
    char c = s[i];
    if (c != '?') {
      if (cnt[c] == 1) dup++;
      cnt[c]++;
    }
    if (i >= lim) {
      char d = s[i - lim];
      if (d != '?') {
	if (cnt[d] == 2) dup--;
	cnt[d]--;
      }
    }
  }
  if (dup == 0) {
    char q = 'A';
    for (ll j = 0; j < n; j++) {
      if (s[j] != '?') cout << s[j];
      else if (j < i - lim || i <= j) cout << 'A';
      else {
	while (cnt[q] > 0) q++;
	cout << q;
	q++;
      }
    }
    cout << endl;
  }else {
    cout << -1 << endl;
  }

  return 0;
}

