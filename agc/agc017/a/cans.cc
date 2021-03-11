#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll power(ll p, ll q) {
  ll ans = 1;
  for (int i = 0; i < q; i++) {
    ans *= p;
  }
  return ans;
}

ll combi(ll n, ll r) {
  if (r == 0) return 1;
  if (r == n) return 1;
  return combi(n-1, r-1) + combi(n-1, r);
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, P; cin >> N >> P;
  int even = 0;
  int odd = 0;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    if (a % 2 == 0) even++;
    else odd++;
  }
  if (P == 0) {
    ll e = power(2, even);
    ll o = 0;
    for (int i = 0; i <= odd; i+= 2) {
      o += combi(odd, i);
    }
    cout << e * o << endl;
  }else {
    ll e = power(2, even);
    ll o = 0;
    for (int i = 1; i <= odd; i+= 2) {
      o += combi(odd, i);
    }
    cout << e * o << endl;
  }
  return 0;
}

