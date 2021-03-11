#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  ll cnt = 0;
  string prev = "";
  for (ll i = 0; i < n; i++) {
    string cur; cin >> cur;
    if (prev != cur) cnt++;
    prev = cur;
  }
  cout << cnt << endl;
    

  return 0;
}

