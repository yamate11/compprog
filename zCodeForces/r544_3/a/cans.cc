#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s, t; cin >> s >> t;
  string s1 = s.substr(0, 2);
  string s2 = s.substr(3, 2);
  string t1 = t.substr(0, 2);
  string t2 = t.substr(3, 2);
  ll x = ((stoi(s1) * 60) + stoi(s2) + (stoi(t1) * 60) + stoi(t2)) / 2;
  ll y = x / 60;
  ll z = x % 60;
  cout << setw(2) << setfill('0') << y << ":" << setw(2) << setfill('0') << z << endl;



  return 0;
}

