#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll N, rate; cin >> N >> rate;
    using sta = pair<ll, ll>;
    vector<sta> pos, zero, neg;
    ll sumpos = 0;
    ll sumneg = 0;
    for (ll i = 0; i < N; i++) {
      ll a, b; cin >> a >> b;
      if (b > 0) {
	sumpos += b;
	pos.emplace_back(a, b);
      }
      else if (b == 0) zero.emplace_back(a, 0);
      else {
	sumneg -= b;
	neg.emplace_back(a + b, -b);
      }
    }
    if (rate + sumpos - sumneg < 0) return false;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    for (auto [a, b] : pos) {
      if (rate < a) return false;
      rate += b;
    }
    for (auto [a, b] : zero) {
      if (rate < a) return false;
    }
    ll nr = rate - sumneg;
    for (auto [u, v] : neg) {
      if (nr < u) return false;
      nr += v;
    }
    return true;
  };

  cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

