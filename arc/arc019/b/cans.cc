#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve() {
  string S; cin >> S;
  ll N = S.size();
  ll cnt = 0;
  for (ll i = 0; i < N/2; i++) {
    if (S.at(i) != S.at(N-1 - i)) cnt++;
  }
  if (cnt >= 2) return 25 * N;
  if (cnt == 1) return 25 * (N-2) + 24 * 2;
  // cnt == 0
  if (N % 2 == 0) return 25 * N;
  else            return 25 * (N-1);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  

  return 0;
}

