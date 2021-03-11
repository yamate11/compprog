#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);

  auto solve = [&](int sign) -> ll {
    ll s = 0;
    ll op = 0;
    for (int i = 0; i < n; i++) {
      s += a.at(i);
      if (sign > 0 && s <= 0) {
	op += 1 - s;
	s = 1;
      }else if (sign < 0 && s >= 0) {
	op += s + 1;
	s = -1;
      }
      sign = -sign;
    }
    return op;
  };

  cout << min(solve(1), solve(-1)) << endl;

  return 0;
}

