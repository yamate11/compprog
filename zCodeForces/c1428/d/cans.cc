#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n; cin >> n;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) cin >> A[i];
    using sta = pair<ll, ll>;
    vector<sta> targets;
    vector<sta> ones;
    ll oidx = 0;
    ll row = 0;
    for (ll i = n-1; i >= 0; i--) {
      if (A[i] == 0) {
      }else if (A[i] == 1) {
	ones.emplace_back(row, i);
	targets.emplace_back(row, i);
	row++;
      }else if (A[i] == 2) {
	if (oidx >= (ll)ones.size()) {
	  cout << "-1\n";
	  return;
	}
	auto [r, c] = ones[oidx++];
	targets.emplace_back(r, i);
      }else if (A[i] == 3) {
	if (oidx >= (ll)ones.size()) {
	  cout << "-1\n";
	  return;
	}
	auto [r, c] = ones[oidx++];
	targets.emplace_back(row, i);
	targets.emplace_back(row, c);
	row++;
      }
    }
    cout << targets.size() << "\n";
    for (auto [r, c] : targets) {
      cout << n - r << " " << c + 1 << "\n";
    }
  };

  solve();

  return 0;
}

