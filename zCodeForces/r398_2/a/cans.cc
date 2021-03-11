#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<bool> has(n + 1);
  ll p = n;
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    has[x] = true;
    bool first = true;
    while (p >= 1 && has[p]) {
      if (first) first = false;
      else cout << " ";
      cout << p;
      p--;
    }
    cout << "\n";
  }


  return 0;
}

