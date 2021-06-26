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

  string S; cin >> S;
  ll w; cin >> w;
  string t;
  ll i = 0;
  ll sz = S.size();
  while (i < sz) {
    t += S[i];
    i += w;
  }
  cout << t << endl;

  return 0;
}

