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
  vector<ll> A(N+1);
  map<ll, ll> mp1;
  map<ll, ll> mp2;
  for (ll i = 1; i <= N; i++) {
    cin >> A.at(i);
    ll k = i - A.at(i);
    ll m = i + A.at(i);
    mp1[k]++;
    mp2[m]++;
  }
  ll cnt = 0;
  for (ll i = 1; i <= N; i++) {
    ll k = i - A.at(i);
    ll m = i + A.at(i);
    cnt += mp2[k] + mp1[m];
  }
  cout << cnt / 2 << endl;
  

  return 0;
}

