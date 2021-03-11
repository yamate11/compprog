#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<ll> X(N), Y(N);
  for (int i = 0; i < N; i++) cin >> X.at(i) >> Y.at(i);
  vector<ll> u(N), v(N);
  ll uMax = -2e9;
  ll uMin = 2e9;
  ll vMax = -2e9;
  ll vMin = 2e9;
  for (int i = 0; i < N; i++) {
    u.at(i) = X.at(i) - Y.at(i);
    v.at(i) = X.at(i) + Y.at(i);
    uMax = max(uMax, u.at(i));
    uMin = min(uMin, u.at(i));
    vMax = max(vMax, v.at(i));
    vMin = min(vMin, v.at(i));
  }
  ll z = max(uMax - uMin, vMax - vMin);
  ll hsize = (z+1) / 2;
  ll u0 = -1;
  ll v0 = -1;
  auto chk = [&](ll uu, ll vv) {
    for (int i = 0; i < N; i++) {
      if (u.at(i) != uu && u.at(i) != uu + 2*hsize &&
	  v.at(i) != vv && v.at(i) != vv + 2*hsize)   return false;
    }
    u0 = uu + hsize;
    v0 = vv + hsize;
    return true;
  };
     chk(uMin,           vMin)
  || chk(uMin,           vMax - 2*hsize)
  || chk(uMax - 2*hsize, vMin) 
  || chk(uMax - 2*hsize, vMax - 2*hsize);
  ll x0 = (u0 + v0) / 2;
  ll y0 = (- u0 + v0) / 2;

  /*
  ll dist = abs(X.at(0) - x0) + abs(Y.at(0) - y0);
  for (int i = 1; i < N; i++) {
    if (abs(X.at(i) - x0) + abs(Y.at(i) - y0) != dist) {
      cout << "NG\n" << "(x0, y0, i) = " << x0 << " " << y0 << " " << i << endl;
      return 0;
    }
  }
  cout << "OK\n";
  */

  cout << x0 << " " << y0 << endl;

  return 0;
}

