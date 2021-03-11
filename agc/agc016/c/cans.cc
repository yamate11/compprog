#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, h, w; cin >> H >> W >> h >> w;
  if (H % h == 0 && W % w == 0) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  ll rev = false;
  if (H % h == 0) {
    swap(H, W);
    swap(h, w);
    rev = true;
  }
  ll y = H / h;
  ll v = y + 1;
  ll vv = -((h - 1) * v + 1);
  vector pat(H, v);
  for (ll i = 0; i < H; i++) pat.at(i) = i % h == h-1 ? vv : v;
  if (rev) {
    for (ll i = 0; i < W; i++) {
      for (ll j = 0; j < H; j++) {
	if (j > 0) cout << " ";
	cout << pat.at(j);
      }
      cout << "\n";
    }
  }else {
    for (ll i = 0; i < H; i++) {
      for (ll j = 0; j < W; j++) {
	if (j > 0) cout << " ";
	cout << pat.at(i);
      }
      cout << "\n";
    }
  }

  return 0;
}

