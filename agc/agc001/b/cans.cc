#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X;
  ll x = N - X;
  ll y = X;
  ll s = N;
  if (x < y) swap(x, y);
  while (y > 0) {
    ll d = x / y;
    ll m = x % y;
    s += 2 * d * y;
    x = y;
    y = m;
  }
  cout << s - x << endl;

  return 0;
}

