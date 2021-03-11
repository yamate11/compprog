#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll sum = 0;
  ll n = s.size();
  for (ll i = 0; i < n; i++) {
    sum += s[i] - '0';
  }
  if (sum % 9 == 0) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

