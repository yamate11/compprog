#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()


bool solve() {
  ll n; cin >> n;
  vector<ll> vec(n);
  for (ll i = 0; i < n; i++) cin >> vec.at(i);

  ll i = 0;

  auto chk = [&](ll k, ll goal) -> bool {
    while (k <= goal) {
      if (vec.at(i++) == k) k++;
      else return false;
    }
    return true;
  };

  ll goal = n;
  while (goal > 0) {
    ll p = vec.at(i++);
    if (!chk(p + 1, goal)) return false;
    goal = p - 1;
  }
  return true;
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll t; cin >> t;
  for (ll i = 0; i < t; i++) cout << (solve() ? "Yes" : "No") << "\n";
  return 0;
}

