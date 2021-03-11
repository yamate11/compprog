#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

bool parlindrome(string s, ll b, ll l) {
  for (ll i = 0; i < l / 2; i++) {
    if (s.at(b + i) != s.at(b + l - 1 - i)) return false;
  }
  return true;
}

bool solve() {
  string S; cin >> S;
  ll N = S.size();
  if (! parlindrome(S, 0, S.size())) return false;
  if (! parlindrome(S, 0, (N-1)/2)) return false;
  if (! parlindrome(S, (N+1)/2, (N-1)/2)) return false;
  return true;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << (solve() ? "Yes\n" : "No\n");
  

  return 0;
}

