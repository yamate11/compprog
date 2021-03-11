#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto op_v = [&](string sa, ll n) -> vector<ll> {
    ll prev = sa.at(0);
    ll i = 1;
    vector<ll> rec;
    for (; i < n; i++) {
      if (sa.at(i) != prev) {
	rec.push_back(i);
	prev = sa.at(i);
	if (i == n) break;
      }
    }
    return rec;
  };

  auto solve = [&](ll n, string& sa, string& sb) -> void {
    auto rec_a = op_v(sa, n);
    if (sa.at(n-1) != sb.at(n-1)) rec_a.push_back(n);
    auto rec_b = op_v(sb, n);
    reverse(rec_b.begin(), rec_b.end());
    for (ll p : rec_b) rec_a.push_back(p);
    cout << rec_a.size();
    for (ll p : rec_a) cout << " " << p;
    cout << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    string sa, sb;
    cin >> sa >> sb;
    solve(n, sa, sb);
  }

  return 0;
}

