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
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  ll s = 0;
  ll c = 1 - N;
  for (ll i = 0; i < N; i++) {
    s += c * A[i];
    c += 2;
  }
  cout << s << endl;

  return 0;
}

