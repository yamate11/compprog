#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


ll f(ll x) {
  if (x == 0) return 0;
  return (x % 10) + f(x / 10);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> ans;
  for (ll i = max(1LL, N - 200); i <= N; i++) {
    if (f(i) + i == N) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (ll x : ans) cout << x << endl;

  return 0;
}

