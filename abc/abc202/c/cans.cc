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
  vector<ll> A(N + 1), B(N + 1), C(N + 1), D(N + 1);
  for (ll i = 1; i <= N; i++) cin >> A[i];
  for (ll i = 1; i <= N; i++) cin >> B[i];
  for (ll i = 1; i <= N; i++) cin >> C[i];
  for (ll i = 1; i <= N; i++) { D[i] = B[C[i]]; }
  vector<ll> cnt(N + 1);
  for (ll i = 1; i <= N; i++) {
    cnt[D[i]] ++;
  }
  ll s = 0;
  for (ll i = 1; i <= N; i++) { s += cnt[A[i]]; }
  cout << s << endl;
    
  
  

  return 0;
}

