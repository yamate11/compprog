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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    string T; cin >> T;
    if (N == 1) {
      if (T == "1") return ll(2e10);
      if (T == "0") return ll(1e10);
      assert(0);
    }
    if (N == 2) {
      if (T == "11") return ll(1e10);
      if (T == "10") return ll(1e10);
      if (T == "01") return ll(1e10) - 1;
      return 0;
    }
    if (T[0] == '0' && T[1] == '0') return 0;
    ll start = 0;
    if (T[0] == '0') start = 2;
    else if (T[0] == '1' && T[1] == '0') start = 1;
    else start = 0;
    for (ll i = 0; i < N; i++) {
      if ((i + start) % 3 == 0 && T[i] != '1') return 0;
      if ((i + start) % 3 == 1 && T[i] != '1') return 0;
      if ((i + start) % 3 == 2 && T[i] != '0') return 0;
    }
    if (start == 0) return (ll(3e10) - N + 3) / 3;
    if (start == 1) return (ll(3e10) - N + 2) / 3;
    if (start == 2) return (ll(3e10) - N + 1) / 3;
    assert(0);
  };

  cout << solve() << endl;

  return 0;
}

