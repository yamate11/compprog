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

  string S; cin >> S;
  reverse(S.begin(), S.end());
  ll N = S.size();
  using info_t = pair<ll, char>;
  vector<info_t> info;
  for (ll i = 1; i+1 < N; i++) {
    if (S[i-1] != S[i] && S[i] == S[i + 1]) {
      info.emplace_back(i, S[i]);
    }
  }
  ll ans = 0;
  vector<ll> ccnt(128);
  ll pos = 0;
  for (auto [idx, c0] : info) {
    for ( ; pos < idx; pos++) {
      ccnt[S[pos]]++;
    }
    ll v = 0;
    for (ll c = 'a'; c <= 'z'; c++) if (c != c0) v += ccnt[c];
    ans += v;
    for (ll c = 'a'; c <= 'z'; c++) ccnt[c] = 0;
    ccnt[c0] = idx;
  }
  cout << ans << endl;

  return 0;
}

