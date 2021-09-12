#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s1 = "101";
  long x = stoll(s1);         // x == 101
  long y = stoll(s1, 0, 2);   // y == 5
  assert(x == 101);
  assert(y == 5);

  ll value = 256;
  stringstream ss;
  ss << hex << value;
  string s = ss.str();  // s == "100"
  assert(s == "100");

  ll value2 = 20;
  string s2 = bitset<8>(value2).to_string(); // s2 == "00010100"
  assert(s2 == "00010100");

  const ll big1 = 1e18;
  const ll big2 = 1e18 + 1;
  cout << big2 << endl;

  double d1 = -26.001;
  ll x1 = ll(d1 + 0.5);
  cout << x1 << endl;

  return 0;
}
