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

  using sta = pair<ll, char>;
  vector<sta> vec;
  for (ll i = 0; i < 3; i++) {
    ll x; cin >> x;
    char c = 'A' + i;
    vec.emplace_back(x, c);
  }
  sort(vec.begin(), vec.end());
  cout << (char)(vec[1].second) << endl;


  return 0;
}

