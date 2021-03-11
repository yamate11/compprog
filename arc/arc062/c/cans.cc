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
  vector<ll> T(N), A(N);
  ll accT = 1;
  ll accA = 1;
  for (ll i = 0; i < N; i++) {
    ll t, a; cin >> t >> a;
    ll jt = (accT + (t-1)) / t;
    ll ja = (accA + (a-1)) / a;
    ll jj = max(jt, ja);
    accT = jj * t;
    accA = jj * a;
  }
  cout << accT + accA << endl;

  return 0;
}

