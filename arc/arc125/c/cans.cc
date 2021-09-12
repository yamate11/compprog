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

  ll N, K; cin >> N >> K;
  vector<ll> A(K);
  for (ll i = 0; i < K; i++) cin >> A[i];
  vector<bool> put(N + 1);
  ll p = 1;
  vector<ll> ans;
  for (ll i = 0; i < K-1; i++) {
    ans.push_back(A[i]);
    put[A[i]] = true;
    for (; p < A[i] && put[p]; p++);
    if (p < A[i]) {
      ans.push_back(p);
      put[p] = true;
      p++;
    }
  }
  for (ll i = N; i >= 1; i--) {
    if (! put[i]) ans.push_back(i);
  }
  for (ll x : ans) cout << x << " ";
  cout << endl;

  return 0;
}

