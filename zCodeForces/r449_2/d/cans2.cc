#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, c; cin >> n >> m >> c;
  vector<ll> vec(n + 1, -1);
  auto ask = []() -> ll {
    ll x; cin >> x;
    return x;
  };
  ll rem = n;
  auto move = [&vec, &rem](ll i, ll x) -> void {
    if (vec[i] < 0) rem--;
    vec[i] = x;
    cout << i << endl;
  };
  while (rem > 0) {
    ll x = ask();
    if (x <= (c + 1) / 2) {
      ll i = 1;
      for ( ; i <= n && vec[i] >= 0 && vec[i] <= x; i++);
      move(i, x);
    }else {
      ll i = n;
      for ( ; i >= 1 && vec[i] >= 0 && vec[i] >= x; i--);
      move(i, x);
    }
  }
  


  return 0;
}

