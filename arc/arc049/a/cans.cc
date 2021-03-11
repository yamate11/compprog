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
  vector<ll> p(5);
  for (ll i = 0; i < 4; i++) cin >> p.at(1+i);
  for (ll i = 0; i < 4; i++) cout << S.substr(p.at(i), p.at(i+1) - p.at(i)) << '"';
  cout << S.substr(p.at(4)) << endl;

  return 0;
}

