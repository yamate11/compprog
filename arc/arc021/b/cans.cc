#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll L; cin >> L;
  vector<ll> B(L);
  ll tot = 0;
  for (ll i = 0; i < L; i++) {
    cin >> B.at(i);
    tot ^= B.at(i);
  }
  if (tot != 0) {
    cout << "-1\n";
    return 0;
  }
  ll cur = 0;
  cout << "0\n";
  for (ll i = 0; i < L-1; i++) {
    cur ^= B.at(i);
    cout << cur << "\n";
  }


  return 0;
}

