#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    vector<ll> cnt(128);
    for (ll j = i; j < N; j++) {
      cnt[S[j]]++;
      if (cnt['A'] == cnt['T'] && cnt['C'] == cnt['G']) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

