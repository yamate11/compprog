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
  set<string> rec;
  for (ll i = 1; i <= N; i++) {
    string s; cin >> s;
    if (rec.find(s) == rec.end()) {
      cout << i << "\n";
      rec.insert(s);
    }
  }

  return 0;
}

