#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; string S; cin >> N >> S;
  vector<ll> cnt(128);
  for (ll i = 0; i < N; i++) cnt[S.at(i)]++;
  cout << (cnt['R'] % 2 + cnt['G'] % 2 + cnt['B'] % 2) << endl;
  return 0;
}

