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
  vector<ll> A(1e5+1, -1);
  ll lim = -1;
  ll lmax = 0;
  ll len = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (A.at(a) > lim) {
      lim = A.at(a);
      len = i - lim;
    }else {
      len++;
      lmax = max(lmax, len);
    }
    A.at(a) = i;
  }
  cout << lmax << endl;

  return 0;
}

