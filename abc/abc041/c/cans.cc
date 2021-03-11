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
  vector<pair<ll, ll>> A;
  for (ll i = 1; i <= N; i++) {
    ll a; cin >> a;
    A.emplace_back(a, i);
  }
  sort(A.begin(), A.end(), greater<pair<ll, ll>>());
  for (pair<ll, ll> p : A) {
    cout << p.second << "\n";
  }
  

  return 0;
}

