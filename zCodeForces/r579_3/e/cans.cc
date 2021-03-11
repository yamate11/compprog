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
  vector<ll> A(n);
  vector<bool> rec(151000);
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    A[i] = a;
  }
  sort(A.begin(), A.end());
  for (ll i = 0; i < n; i++) {
    ll a = A[i];
    if (a >= 2 && !rec[a-1]) {
      rec[a-1] = true;
    }else if (!rec[a]) {
      rec[a] = true;
    }else if (!rec[a+1]) {
      rec[a+1] = true;
    }
  }
  ll cnt = 0;
  for (bool b : rec) {
    if (b) cnt++;
  }
  cout << cnt << endl;


  return 0;
}

