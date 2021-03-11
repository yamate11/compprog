#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  if (n >= 4 && m >= 4) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 1 || m == 1) {
    cout << 0 << endl;
    return 0;
  }
  vector<string> inp(n);
  for (ll i = 0; i < n; i++) cin >> inp.at(i);
  vector<vector<int>> vec;
  ll p, q;
  if (n == 2 || n == 3) {
    vec = vector(n, vector(m, 0));
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < m; j++) {
	vec[i][j] = inp[i][j] - '0';
      }
    }
    p = n;
    q = m;
  }else {
    vec = vector(m, vector(n, 0));
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < m; j++) {
	vec[j][i] = inp[i][j] - '0';
      }
    }
    p = m;
    q = n;
  }
  if (p == 2) {
    auto chk2 = [&](ll z) -> ll {
      ll cnt = 0;
      for (ll i = 0; i < q; i++) {
	if ((vec[0][i] + vec[1][i]) % 2 != z) cnt++;
	z = 1 - z;
      }
      return cnt;
    };
    ll fst = chk2(0);
    ll snd = chk2(1);
    cout << min(fst, snd) << endl;
    return 0;
  }else { // p == 3;
    auto chk3 = [&](ll z0, ll z2) -> ll {
      ll cnt = 0;
      for (ll i = 0; i < q; i++) {
	{
	  ll y1 = 0;
	  ll y0 = z0;
	  ll y2 = z2;
	  ll diff1 = abs(y0 - vec[0][i]) + abs(y1 - vec[1][i]) + abs(y2 - vec[2][i]);
	  y1 = 1;
	  y0 = 1 - z0;
	  y2 = 1 - z2;
	  ll diff2 = abs(y0 - vec[0][i]) + abs(y1 - vec[1][i]) + abs(y2 - vec[2][i]);
	  cnt += min(diff1, diff2);
	}
	z0 = 1 - z0;
	z2 = 1 - z2;
      }
      return cnt;
    };
    ll ev = LLONG_MAX;
    ev = min(ev, chk3(0, 0));
    ev = min(ev, chk3(1, 0));
    ev = min(ev, chk3(0, 1));
    ev = min(ev, chk3(1, 1));
    cout << ev << endl;
    return 0;
  }


  return 0;
}

