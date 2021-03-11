#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, n1, n2; cin >> n >> n1 >> n2;
  if (n1 > n2) swap(n1, n2);
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  sort(A.begin(), A.end(), greater<ll>());
  ll s1 = 0, s2 = 0;
  for (ll i = 0; i < n1; i++) s1 += A[i];
  for (ll i = n1; i < n1 + n2; i++) s2 += A[i];
  cout << double(s1) / n1 + double(s2) / n2 << endl;


  return 0;
}

