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
    ll N; cin >> N;
    string s = to_string(N);
    ll i = s.size() - 1;
    for (; i >= 0 && s[i] == '0'; i--);
    if (i < 0) return true;
    s.resize(i + 1);
    string t(s);
    reverse(t.begin(), t.end());
    return s == t;
  };
  cout << (solve() ? "Yes" : "No") << endl;

  return 0;
}

