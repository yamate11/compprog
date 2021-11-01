#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // vector<ll> A(N);
  vector<ll> pos(51, -1);
  for (ll i = 1; i <= N; i++) {
    ll a; cin >> a;
    if (pos[a] < 0) pos[a] = i;
  }
  for (ll q = 0; q < Q; q++) {
    ll t; cin >> t;
    ll orig = pos[t];
    cout << orig << " ";
    for (ll i = 1; i <= 50; i++) {
      if (i == t) pos[t] = 1;
      else if (pos[i] < orig) pos[i]++;
    }
  }
  cout << endl;


  return 0;
}

