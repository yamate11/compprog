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
  bool res = false;
  for (ll i = 0; i < n; i++) {
    string s; ll bef, aft; cin >> s >> bef >> aft;
    if (bef >= 2400 && bef < aft) res = true;
  }
  cout << (res ? "YES" : "NO") << endl;


  return 0;
}

