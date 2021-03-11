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
  map<ll, ll> mp1, mp2;
  for (ll i = 0; i < N; i++) {
    ll d; cin >> d;
    mp1[d]++;
  }
  ll M; cin >> M;
  for (ll i = 0; i < M; i++) {
    ll d; cin >> d;
    mp2[d]++;
  }
  for (auto t : mp2) {
    ll x, n; tie(x, n) = t;
    if (mp1[x] < n) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}

