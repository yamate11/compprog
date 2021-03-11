#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  while (true) {
    ll x; cin >> x;
    if (x == -1) break;
    if (x == 1) {
      ll y = 10 / (x - 1);
      x += y;
    }
    ll z = x * x;
    cout << z << endl;
  }
  return 0;
}
