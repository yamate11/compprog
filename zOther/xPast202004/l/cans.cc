#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K, D; cin >> N >> K >> D;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  if ((K - 1) * D + 1 > N) {
    cout << -1 << endl;
    return 0;
  }
  vector<ll> ans;
  ll lastPos = -D*2;
  deque<ll> deq;
  for (ll i = 0; i < N - (K-1) * D; i++) {
    if (i == 0)  {
      deq.push_back(A.at(i));
      lastPos = 0;
    }else {
      if (deq.back() <= A.at(i)) {
	if (lastPos + D <= i) {
	  deq.push_back(A.at(i));
	  lastPos = i;
	}
      }else {
	while (!deq.empty() && deq.back() > A.at(i)) deq.pop_back();
	deq.push_back(A.at(i));
	lastPos = i;
      }
    }
  }
  ll x = deq.front(); deq.pop_front();
  ans.push_back(x);
  for (ll k = 0; k < K-1; k++) {
    for (ll j = 0; j < D; j++) {
      ll i = N - (K-1) * D + k * D + j;
      if (deq.empty() || deq.back() <= A.at(i)) {
	if (lastPos + D <= i) {
	  deq.push_back(A.at(i));
	  lastPos = i;
	}
      }else {
	while (!deq.empty() && deq.back() > A.at(i)) deq.pop_back();
	deq.push_back(A.at(i));
	lastPos = i;
      }
    }
    ll x1 = deq.front(); deq.pop_front();
    ans.push_back(x1);
  }
  for (ll i = 0; i < K; i++) {
    if (i > 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  

  return 0;

}

