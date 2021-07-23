#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  string ans;
  for (ll i = 0; i < N; i++) {
    if (S[i] == '0') continue;
    if (i % 2 == 0) ans = "Takahashi";
    else ans = "Aoki";
    cout << ans << endl;
    return 0;
  }

  return 0;
}

