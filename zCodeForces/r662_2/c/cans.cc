#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll N, const auto& A) -> ll {
    vector cnt(N+1, 0LL);
    for (ll a : A) cnt[a]++;
    vector<ll> vec;
    for (ll i = 1; i <= N; i++) if (cnt[i] > 0) vec.push_back(cnt[i]);
    sort(vec.begin(), vec.end(), greater<ll>());
    auto check = [&](ll dist) -> bool {
      ll p = N % (dist + 1);
      ll cyc = N / (dist + 1);
      for (ll i = 0; i < p; i++) {
	if (vec[i] > cyc + 1) return false;
	if (vec[i] <= cyc) return true;
      }
      return vec[p] <= cyc;
    };
    ll ans = binsearch<ll>(check, 0, N-1);
    return ans;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a.at(i);
    cout << solve(n, a) << "\n";
  }

  return 0;
}

