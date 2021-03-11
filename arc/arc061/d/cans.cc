#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll enc(ll y, ll x) { return (y << 32) + x; }

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N; cin >> H >> W >> N;
  unordered_set<ll> points;
  vector<ll> answer(10);

  answer.at(0) = (H-2) * (W-2);
  for (int _i = 0; _i < N; _i++) {
    ll a, b; cin >> a >> b; a--; b--;
    for (int y = -1; y <= 1; y++) {
      for (int x = -1; x <= 1; x++) {
	ll p = a + y;
	ll q = b + x;
	if (p < 1 || p >= H-1 || q < 1 || q >= W-1) continue;
	int cnt = 0;
	for (int u = -1; u <= 1; u++) {
	  for (int v = -1; v <= 1; v++) {
	    ll s = p + u;
	    ll t = q + v;
	    if (points.count(enc(s, t)) == 1) cnt++;
	  }
	}
	answer.at(cnt)--;
	answer.at(cnt+1)++;
      }
    }
    points.insert(enc(a, b));
  }

  for (int i = 0; i < 10; i++) cout << answer.at(i) << "\n";

  return 0;
}

