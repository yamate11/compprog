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
    string s; cin >> s;
    ll k = s.size();
    vector num(3, 0LL);
    ll t = 0;
    for (ll i = 0; i < k; i++) {
      ll x = s[i] - '0';
      ll y = x % 3;
      num[y]++;
      t += y;
    }
    t = t % 3;
    if (t == 0) return 0;
    if (k == 1) return -1;
    if (k == 2) {
      if (num[0] == 0) return -1;
      else return 1;
    }
    if (t == 1) {
      if (num[1] > 0) return 1;
      return 2;
    }else if (t == 2) {
      if (num[2] > 0) return 1;
      return 2;
    }else assert(0);
  };
  cout << solve() << endl;

  return 0;
}

