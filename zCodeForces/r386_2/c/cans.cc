#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll s, x1, x2; cin >> s >> x1 >> x2;
  ll t1, t2; cin >> t1 >> t2;
  ll p, d; cin >> p >> d;
  ll cand1 = abs(x2 - x1) * t2;
  ll cand2 = -1;
  if (d == 1) {
    if (x1 < x2) {
      if (p <= x1) {
	cand2 = (x2 - p) * t1;
      }else {
	cand2 = (s - p + s + x2) * t1;
      }
    }else {
      cand2 = (s - p + s - x2) * t1;
    }
  }else {
    if (x1 > x2) {
      if (p >= x1) {
	cand2 = (p - x2) * t1;
      }else {
	cand2 = (p + s + s - x2) * t1;
      }
    }else {
      cand2 = (p + x2) * t1;
    }
  }
  cout << min(cand1, cand2) << endl;

  return 0;
}

