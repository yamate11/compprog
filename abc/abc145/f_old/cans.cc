#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


typedef pair<ll, ll> Pair;

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, K; cin >> N >> K;
  vector<ll> H(N+1);
  for (int i = 0; i < N; i++) cin >> H.at(i);

  vector<vector<Pair>> st(K+1);
  st.at(0).emplace_back(0, 0);

  for (int i = 0; i < N; i++) {
    vector<vector<Pair>> newst(K+1);
    for (int k = 0; k < K; k++) {
      for (Pair p : st.at(k)) {
	if (p.first != H.at(i)) newst.at(k+1).push_back(p);
      }
    }
    for (int k = 0; k <= K; k++) {
      if (st.at(k).size() == 0) continue;
      ll cmin = LLONG_MAX;
      for (Pair p : st.at(k)) {
	ll ht = p.first;
	ll cost = p.second;
	cmin = min(cmin, cost + max(H.at(i) - ht, 0LL));
      }
      newst.at(k).emplace_back(H.at(i), cmin);
    }
    st = move(newst);
  }
  ll ans = LLONG_MAX;
  for (int k = 0; k <= K; k++) {
    for (Pair p : st.at(k)) {
      ans = min(ans, p.second);
    }
  }
  cout << ans << endl;

  return 0;
}

