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

  ll N, X; cin >> N >> X;
  string S; cin >> S;

  ll m = X;
  for (ll i = 0; i < N; i++) {
    if (S[i] == 'o') m++;
    else if (m > 0) m--;
  }
  cout << m << endl;

  return 0;
}

