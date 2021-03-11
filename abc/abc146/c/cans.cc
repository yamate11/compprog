#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B, X; cin >> A >> B >> X;
  if (X < A + B) {
    cout << "0\n";
    return 0;
  }
  ll t = 1;
  ll d = 1;
  while (t <= (ll)(1e9) && A * t + B * d <= X) {
    t *= 10;
    d ++;
  }
  t /= 10;
  d --;
  if (t == (ll)(1e9)) {
    cout << t << endl;
  }else {
    ll xx = (X - B * d) / A;
    cout << min(t * 10 - 1, xx) << endl;
    // cout << xx << endl;
  }

  return 0;
}

