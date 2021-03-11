#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll big = 1e16;

ll solve() {
  ll N; cin >> N;
  vector<ll> A(N+1);
  for (ll i = 0; i <= N; i++) cin >> A.at(i);

  if (N == 0) {
    if (A.at(0) == 1) return 1;
    else return -1;
  }

  if (A.at(0) != 0) return -1;
  vector<ll> p(N+1);
  p.at(0) = 1;
  for (ll i = 1; i < N; i++) {
    if (p.at(i-1) >= big) p.at(i) = big;
    else {
      ll x = p.at(i-1) * 2 - A.at(i);
      if (x <= 0) return -1;
      p.at(i) = x;
    }
  }
  if (p.at(N-1) * 2 < A.at(N)) return -1;
  vector<ll> r(N+1);
  r.at(N) = 0;
  for (ll i = N-1; i >= 0; i--) {
    ll t = r.at(i+1) + A.at(i+1);
    if (t <= p.at(i)) r.at(i) = t;
    else              r.at(i) = p.at(i);
  }
  ll ans = 0;
  for (ll i = 0; i <= N; i++) {
    ans += A.at(i) + r.at(i);
  }
  return ans;
  
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

