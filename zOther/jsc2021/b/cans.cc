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

  ll N, M; cin >> N >> M;
  vector<ll> A(N), B(M);
  set<ll> SA, SB;
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    SA.insert(A[i]);
  }
  for (ll i = 0; i < M; i++) {
    cin >> B[i];
    SB.insert(B[i]);
  }
  vector<ll> ans;
  for (ll i = 0; i < N; i++) {
    if (SB.find(A[i]) == SB.end()) { ans.push_back(A[i]); }
  }
  for (ll i = 0; i < M; i++) {
    if (SA.find(B[i]) == SA.end()) { ans.push_back(B[i]); }
  }
  sort(ans.begin(), ans.end());
  for (ll a: ans) {
    cout << a << " ";
  }
  cout << endl;


  return 0;
}

