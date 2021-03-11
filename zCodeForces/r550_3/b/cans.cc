#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = []() -> ll {
    ll n; cin >> n;
    vector<ll> odd, even;
    for (ll i = 0; i < n; i++) {
      ll a; cin >> a;
      if (a % 2 == 0) even.push_back(a);
      else odd.push_back(a);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    ll no = odd.size();
    ll ne = even.size();
    if (abs(ne - no) <= 1) return 0;
    ll sum = 0;
    if (ne < no) {
      for (ll i = 0; i < no - ne - 1; i++) sum += odd[i];
    }else {
      for (ll i = 0; i < ne - no - 1; i++) sum += even[i];
    }
    return sum;
  };
  cout << solve() << endl;

  return 0;
}

