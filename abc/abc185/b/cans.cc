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

  ll N, M, T; cin >> N >> M >> T;
  vector<ll> A(M), B(M);
  for (ll i = 0; i < M; i++) cin >> A[i] >> B[i];
  ll cur = N;
  ll pt = 0;
  for (ll i = 0; i < M; i++) {
    cur -= (A[i] - pt);
    if (cur <= 0) {
      cout << "No\n";
      return 0;
    }
    cur += B[i] - A[i];
    cur = min(cur, N);
    pt = B[i];
  }
  cur -= (T - pt);
  if (cur <= 0) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  



  return 0;
}

