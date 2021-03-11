#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve() {
  ll N, M; cin >> N >> M;
  vector<ll> cc(N, -1);
  for (ll i = 0; i < M; i++) {
    ll s, c; cin >> s >> c; 
    s = N - s;
    if (cc.at(s) >= 0 && cc.at(s) != c) return -1;
    cc.at(s) = c;
  }
  if (N > 1 && cc.at(N-1) == 0) return -1;
  if (cc.at(N-1) == -1) {
    if (N > 1) cc.at(N-1) = 1;
    else       cc.at(N-1) = 0;
  }
  for (ll i = N-2; i >= 0; i--) {
    if (cc.at(i) == -1) cc.at(i) = 0;
  }
  if (N == 3) return cc.at(2) * 100 + cc.at(1) * 10 + cc.at(0);
  if (N == 2) return cc.at(1) * 10 + cc.at(0);
  return cc.at(0);
  
}  


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

