#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<int, int> mp;
  mp[0] = 5;
  mp[10] = 3;
  map<int, int>::iterator it2;
  it2 = mp.lower_bound(7);
  it2->second = 9;
  
}
