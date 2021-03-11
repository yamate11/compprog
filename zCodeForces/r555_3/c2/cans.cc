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
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];
  ll p = 0, q = n - 1;
  string ans;
  ll prev = -1;
  while (p <= q) {
    if (prev >= a[p] && prev >= a[q]) break;
    else if (p == q) {
      ans += 'R';
      break;
    } else if (prev >= a[p]) {
      prev = a[q];
      ans += 'R';
      q--;
    }else if (prev >= a[q]) {
      prev = a[p];
      ans += 'L';
      p++;
    }else {
      if (a[p] < a[q]) {
	prev = a[p];
	ans += 'L';
	p++;
      }else if (a[q] < a[p]) {
	prev = a[q];
	ans += 'R';
	q--;
      }else {
	ll kp = 0;
	while (a[p + kp] < a[p + 1 + kp]) kp++;
	ll kq = 0;
	while (a[q - kq] < a[q - 1 - kq]) kq++;
	if (kp > kq) for (ll i = 0; i <= kp; i++) ans += 'L';
	else for (ll i = 0; i <= kq; i++) ans += 'R';
	break;
      }
    }
  }
  cout << ans.size() << endl;
  cout << ans << endl;

  return 0;
}

