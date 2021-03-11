#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = []() -> ll {
    ll N, M; cin >> N >> M;
    vector<ll> A, B;
    using StA = pair<ll, ll>;
    vector<StA> BA;
    for (ll i = 0; i < M; i++) {
      ll a, b; cin >> a >> b;
      A.push_back(a);
      B.push_back(b);
      BA.emplace_back(b, a);
    }
    sort(BA.begin(), BA.end(), greater<StA>());
    sort(A.begin(), A.end(), greater<ll>());
    ll ans = 0;
    ll sumA = 0;
    ll idxA = 0;
    for (ll i = 0; i < M; i++) {
      auto [b, a] = BA.at(i);
      while (idxA < min(M, N) && A.at(idxA) > b) {
	sumA += A.at(idxA);
	idxA++;
      }
      if (idxA == N) {
	ans = max(ans, sumA);
	return ans;
      }else {
	ll cur = sumA;
	if (idxA < M && a <= A.at(idxA)) {
	  cur += a + (N - idxA - 1) * b;
	}else {
	  cur += (N - idxA) * b;
	}
	ans = max(ans, cur);
      }
    }
    return ans;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << endl;
  

  return 0;
}

