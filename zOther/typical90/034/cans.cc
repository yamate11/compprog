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
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  map<ll, ll> mp;
  ll cnt = 0;
  ll p = 0;
  ll q = 0;
  ll ans = 0;
  for (; q < N; q++) {
    auto it = mp.find(A[q]);
    if (it != mp.end()) {
      it->second++;
    }else {
      if (cnt == K) break;
      cnt++;
      mp[A[q]] = 1;
    }
  }
  ans = q;
  while (q < N) {
    while (true) {
      auto it = mp.find(A[p++]);
      if (it->second == 1) {
        mp.erase(it);
        break;
      }else {
        it->second --;
      }
    }
    mp[A[q]] = 1;
    while (++q < N) {
      auto it = mp.find(A[q]);
      if (it == mp.end()) break;
      it->second++;
    }
    ans = max(ans, q - p);
  }
  cout << ans << endl;


  return 0;
}

