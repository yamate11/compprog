#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<ll> t(N);
  for (ll i = 0; i < N; i++) cin >> t.at(i);
  for (ll i = 2; i < N; i++) {
    if (t.at(i-2) + t.at(i-1) + t.at(i) < K) {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << "-1\n";

  return 0;
}

