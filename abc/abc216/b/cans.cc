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
  vector<string> s1(N), s2(N);
  for (ll i = 0; i < N; i++) {
    cin >> s1[i] >> s2[i];
  }
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      if (s1[i] == s1[j] && s2[i] == s2[j]) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";

  return 0;
}

