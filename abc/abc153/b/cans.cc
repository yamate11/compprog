#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, N; cin >> H >> N;
  ll tot = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    tot += a;
  }
  cout << (tot >= H ? "Yes" : "No") << endl;

  return 0;
}

