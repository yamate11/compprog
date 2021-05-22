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
  using sta = pair<ll, string>;
  vector<sta> TS(N);
  for (ll i = 0; i < N; i++) {
    string s; ll t; cin >> s >> t;
    TS.emplace_back(t, s);
  }
  sort(TS.begin(), TS.end(), greater<sta>());
  cout << TS[1].second << endl;
  return 0;
}

