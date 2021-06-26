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

  string N; cin >> N;
  ll K; cin >> K;
  if (N == "0") {
    cout << 0 << endl;
    return 0;
  }
  string s = N;
  for (; K > 0; K--) {
    ll x = 0;
    for (size_t i = 0; i < s.size(); i++) {
      x = 8 * x + s[i] - '0';
    }
    s = "";
    while (x > 0) {
      ll z = x % 9;
      s += (z == 8 ? '5' : '0' + z);
      x /= 9;
    }
    reverse(s.begin(), s.end());
  }
  cout << s << endl;

  return 0;
}

