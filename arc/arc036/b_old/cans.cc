#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

void updMax(ll& x, const ll y) { x = max(x, y); }

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> h(N);
  for (ll i = 0; i < N; i++) cin >> h.at(i);
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  ll len = 0;
  ll t = 0;
  if (h.at(0) > h.at(1)) {
    for ( ; t+1 < N && h.at(t) > h.at(t+1); t++) ;
    len = t+1;
  }
  while (t+1 < N) {
    ll t0 = t;
    for ( ; t+1 < N && h.at(t) < h.at(t+1); t++) ;
    if (t+1 < N) {
      for ( ; t+1 < N && h.at(t) > h.at(t+1); t++) ;
    }
    updMax(len, t - t0 + 1);
  }
  cout << len << endl;

  return 0;
}

