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
  using sta = pair<ll, ll>;
  vector<sta> A;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    A.emplace_back(a, i + 1);
  }
  sort(A.begin(), A.end(), greater<sta>());
  cout << A[1].second << endl;

  return 0;
}

