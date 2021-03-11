#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> A(n), B, C;
  for (ll i = 0; i < n; i++) cin >> A[i];
  sort(A.begin(), A.end());
  for (ll i = 0; i < n; i++) {
    if (B.empty() || B[B.size()-1] < A[i]) B.push_back(A[i]);
    else if (C.empty() || C[C.size() - 1] < A[i]) C.push_back(A[i]);
    else {
      cout << "NO\n";
      return 0;
    }
  }
  reverse(C.begin(), C.end());
  cout << "YES\n";
  cout << B.size() << endl;
  for (ll i = 0; i < (ll)B.size(); i++) {
    if (i > 0) cout << " ";
    cout << B[i];
  }
  cout << endl;
  cout << C.size() << endl;
  for (ll i = 0; i < (ll)C.size(); i++) {
    if (i > 0) cout << " ";
    cout << C[i];
  }
  cout << endl;

  return 0;
}

