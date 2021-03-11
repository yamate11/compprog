#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<string, ll> poly;
  poly["Tetrahedron"] = 4;
  poly["Cube"] = 6;
  poly["Octahedron"] = 8;
  poly["Dodecahedron"] = 12;
  poly["Icosahedron"] = 20;

  ll n; cin >> n;
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    string s; cin >> s;
    sum += poly[s];
  }
  cout << sum << endl;

  return 0;
}

