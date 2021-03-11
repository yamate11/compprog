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
  stringstream ss(S);
  ll x; ss >> x;
  ll t = 0;
  for (ll i = 0; i < (ll)S.size(); i++) {
    t += S.at(i) - '0';
  }
  cout << (x % t == 0 ? "Yes" : "No") << endl;

  return 0;
}

