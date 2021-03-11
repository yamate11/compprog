#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

struct MyExc : exception {};


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using Pair = pair<ll, ll>;

  auto prt = [&](ll x, ll y) -> void {
    cout << x+1 << " " << y+1 << "\n";
  };

  auto solve = [&](ll n, ll m, auto& de, auto& ue) -> void {
    vector nbr(n, vector<ll>());
    for (auto [x, y] : de) nbr.at(x).push_back(y);
    vector<bool> visited(n);
    vector<bool> onstack(n);
    vector<ll> rank(n, -1LL);
    
    auto check = [&](auto rF, ll i) -> ll {
      if (onstack.at(i)) throw MyExc();
      onstack.at(i) = true;
      if (!visited.at(i)) {
	visited.at(i) = true;
	ll r = 0;
	for (ll x : nbr.at(i)) r = max(r, 1 + rF(rF, x));
	rank.at(i) = r;
      }
      onstack.at(i) = false;
      return rank.at(i);
    };

    for (ll i = 0; i < n; i++) check(check, i);
    cout << "YES\n";
    for (auto [x, y] : de) prt(x, y);
    for (auto [x, y] : ue) {
      if (rank.at(x) >= 0 && rank.at(y) >= 0) {
	if (rank.at(x) > rank.at(y)) prt(x, y);
	else if (rank.at(x) < rank.at(y)) prt(y, x);
	else if (x > y) prt(x, y);
	else prt(y, x);
      }
      else if (rank.at(x) >= 0) prt(x, y);
      else if (rank.at(y) >= 0) prt(y, x);
      else if (x > y) prt(x, y);
      else prt(y, x);
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n, m; cin >> n >> m;
    vector<Pair> de, ue;
    for (ll i = 0; i < m; i++) {
      ll typ, x, y; cin >> typ >> x >> y; x--; y--;
      if (typ == 1) de.emplace_back(x, y);
      else ue.emplace_back(x, y);
    }
    try {
      solve(n, m, de, ue);
    }catch(const MyExc& e) {
      cout << "NO\n";
    }
  }

  return 0;
}

