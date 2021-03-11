#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll n = S.size();
  string t;
  for (ll i = 0; i < n; i++) {
    t = t + "x";
  }
  cout << t << endl;

  return 0;
}

