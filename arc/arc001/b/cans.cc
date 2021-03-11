#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll f(ll x) {
  if (x < 0) return f(-x);
  if (x <= 3) return x;
  if (x >= 10) return 1 + f(x - 10);
  if (x > 5) return min(1 + f(10 - x), 1 + f(x - 5));
  if (x == 5) return 1;
  return min(1 + f(5 - x), 1 + f(x - 1));
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B; cin >> A >> B;
  cout << f(A - B) << endl;

  return 0;
}

