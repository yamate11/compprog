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
  if (N == 0) {
    cout << 0 << endl;
    return 0;
  }
  string s;
  while (N > 0) {
    ll q = N % 36;
    if (q < 10) s += '0' + q;
    else s += 'A' + (q - 10);
    N /= 36;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;

  return 0;
}

