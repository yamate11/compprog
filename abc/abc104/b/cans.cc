#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool solve() {
  string S; cin >> S;
  ll N = S.size();
  if (S.at(0) != 'A') return false;
  ll cnt = 0;
  ll p = -1;
  for (ll i = 2; i <= N-2; i++) {
    if (S.at(i) == 'C') {
      cnt++;
      p = i;
    }
  }
  if (cnt != 1) return false;
  for (ll i = 1; i < N; i++) {
    if (i == p) continue;
    if (S.at(i) < 'a' || 'z' < S.at(i)) return false;
  }
  return true;
}



int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "AC\n" : "WA\n");

  return 0;
}

