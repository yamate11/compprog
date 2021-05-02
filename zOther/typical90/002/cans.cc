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

  vector<int> eff(21);
  vector<vector<string>> seq(21);
  seq[2] = vector<string>({"()"});
  eff[0] = eff[2] = 1;
  auto func = [&](auto rF, ll n) -> vector<string>& {
    if (n % 2 == 1) return seq[n];
    if (!eff[n]) {
      eff[n] = 1;
      for (string t : rF(rF, n-2)) seq[n].push_back("(" + t + ")");
      for (ll i = 2; i <= n - 2; i += 2) {
        ll j = n - i;
        if (i > j) break;
        for (string t1 : rF(rF, i)) {
          for (string t2 : rF(rF, j)) {
            seq[n].push_back(t1 + t2);
            if (i < j) seq[n].push_back(t2 + t1);
          }
        }
      }

    }
    sort(seq[n].begin(), seq[n].end());
    seq[n].erase(unique(seq[n].begin(), seq[n].end()), seq[n].end());
    return seq[n];
  };
  for (string s : func(func, N)) cout << s << "\n";
  
  
  return 0;
}

