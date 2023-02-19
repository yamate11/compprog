#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main() {
  map<int, int> mp;
  mp[0] = 10;
  mp[1] = 20;
  auto it1 = mp.end();
  auto it2 = it1; it2--;
  auto it3 = it2; it3--;
  // auto it4 = it3; it4++;
  cout << it1->second << endl;
  cout << it2->second << endl;
  cout << it3->second << endl;
  // cout << it4->second << endl;
  
}
