#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<vector<ll>> nbr(N);
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr.at(a).push_back(b);
    nbr.at(b).push_back(a);
  }
  vector<ll> nEven, nOdd;
  auto dfs = [&](const auto& recF, ll n, ll p, ll d) -> void {
    if (d == 0) nEven.push_back(n);
    else        nOdd.push_back(n);
    for (ll c : nbr.at(n)) {
      if (c == p) continue;
      recF(recF, c, n, 1-d);
    }
  };
  dfs(dfs, 0, -1, 0);
  vector<ll> ans(N);
  auto ass1 = [&](ll i, ll& p) -> bool {
    if (p <= N) {
      ans.at(i) = p;
      p += 3;
      return true;
    }else {
      return false;
    }
  };
  ll n0 = 3, n1 = 1, n2 = 2;
  if ((ll)nEven.size() <= N / 3) {
    for (ll i : nEven) ass1(i, n0);
    for (ll i : nOdd)  ass1(i, n0) || ass1(i, n1) || ass1(i, n2);
  }else if ((ll)nOdd.size() <= N / 3) {
    for (ll i : nOdd)  ass1(i, n0);
    for (ll i : nEven)  ass1(i, n0) || ass1(i, n1) || ass1(i, n2);
  }else {
    for (ll i : nEven) ass1(i, n1) || ass1(i, n0);
    for (ll i : nOdd)  ass1(i, n2) || ass1(i, n0);
  }
  for (ll i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}

