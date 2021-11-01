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

  auto solve = [&]() -> bool {
    string S; cin >> S;
    if (S[3] != '-') return false;
    for (ll i = 0; i < (ll)S.size(); i++) {
      if (i == 3) continue;
      if (! ('0' <= S[i] && S[i] <= '9')) return false;
    }
    return true;
  };

  cout << (solve() ? "Yes" : "No") << endl;

  return 0;
}

