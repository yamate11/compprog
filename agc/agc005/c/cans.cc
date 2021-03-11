#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool solve() {
  ll N; cin >> N;
  vector<ll> v(N);
  ll amin = 1000;
  ll amax = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    v.at(a)++;
    amin = min(amin, a);
    amax = max(amax, a);
  }
  if (amin == 1) {
    if (N == 2) return v.at(1) == 2;
    else return v.at(1) == 1 && v.at(2) == N - 1;
  }
  if (v.at(amin) >= 3) return false;
  else if (v.at(amin) == 1) {
    if (amax != 2 * amin) return false;
    for (ll i = amin + 1; i <= amax; i++) if (v.at(i) <= 1) return false;
    return true;
  }else if (v.at(amin) == 2) {
    if (amax != 2 * amin - 1) return false;
    for (ll i = amin + 1; i <= amax; i++) if (v.at(i) <= 1) return false;
    return true;
  }else {
    assert(0);
  }
  
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cout << (solve() ? "Possible" : "Impossible") << endl;

  return 0;
}

