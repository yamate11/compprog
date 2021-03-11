#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s = bitset<64>(1040).to_string();
  cout << s << endl;
    
  cout << "hex, 100" << hex << 100 << endl;
  cout << "oct, 100" << oct << 100 << endl;
  cout << dec;

  ll x1 = 1e9;
  ll x2 = 1e9 + 1;
  ll x3 = 1e10;
  ll x4 = 1e10 + 1;
  ll x5 = 1e18;
  ll x6 = 1e18 + 1;
  ll x7 = ll(1e18) + 1;

  cout << x1 << endl;
  cout << x2 << endl;
  cout << x3 << endl;
  cout << x4 << endl;
  cout << x5 << endl;
  cout << x6 << endl;
  cout << x7 << endl;

}
