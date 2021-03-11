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
  ll dmax = 0;
  ll dsum = 0;
  for (ll i = 0; i < N; i++) {
    ll d; cin >> d;
    dsum += d;
    dmax = max(dmax, d);
  }
  ll dother = dsum - dmax;
  cout << dsum << endl;
  cout << (dmax > dother ? dmax - dother : 0) << endl;

  return 0;
}

