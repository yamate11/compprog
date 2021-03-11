#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve() {
  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  if (K == 1) return N;
  ll cnt = 0;
  ll s = -1;
  for (ll i = 0; i < N-1; i++) {
    if (A.at(i) < A.at(i+1)) {
      if (i - s >= K-1) cnt++;
    }else {
      s = i;
    }
  }
  return cnt;
  

}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

