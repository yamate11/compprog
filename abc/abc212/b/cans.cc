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

  string s; cin >> s;
  vector<ll> v(4);
  for (ll i = 0; i < 4; i++) v[i] = s[i] - '0';
  if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) {
    cout << "Weak" << "\n";
  }else {
    if (v[1] == (v[0] + 1) % 10 &&
        v[2] == (v[1] + 1) % 10 &&
        v[3] == (v[2] + 1) % 10) {
      cout << "Weak\n";
    }else {
      cout << "Strong\n";
    }
  }

  return 0;
}

