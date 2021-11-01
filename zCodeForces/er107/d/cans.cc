#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  string ans;
  while (true) {
    for (ll i = 0; i < K; i++) {
      ans += (char)('a' + i);
      for (ll j = i + 1; j < K; j++) {
        ans += (char)('a' + i);
        ans += (char)('a' + j);
      }
    }
    if ((ll)ans.size() >= N) {
      cout << ans.substr(0, N) << endl;
      return 0;
    }
  }


  return 0;
}

