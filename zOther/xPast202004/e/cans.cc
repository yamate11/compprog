#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> ans;
  ll N; cin >> N;
  vector<ll> A(N+1);
  for (ll i = 1; i <= N; i++) { cin >> A.at(i); }
  for (ll i = 1; i <= N; i++) {
    ll cnt = 0;
    ll x = i;
    while (true) {
      x = A.at(x);
      cnt++;
      if (x == i) {
	ans.push_back(cnt);
	break;
      }
    }
  }
  for (ll i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}

