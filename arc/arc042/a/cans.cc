#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> a(M);
  for (ll i = 0; i < M; i++) {
    ll x; cin >> x; x--;
    a.at(i) = x;
  }
  vector<int> ans(N);
  vector<bool> seen(N);
  ll idx = 0;
  for (ll i = M-1; i >= 0; i--) {
    ll x = a.at(i);
    if (seen.at(x)) continue;
    seen.at(x) = true;
    ans.at(idx++) = x;
  }
  for (ll i = 0; i < N; i++) {
    if (!seen.at(i)) ans.at(idx++) = i;
  }
  for (ll i = 0; i < N; i++) {
    cout << ans.at(i) + 1 << "\n";
  }
  


  return 0;
}

