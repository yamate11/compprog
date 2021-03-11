#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int sch(ll j, auto& bs) {
  for (ll i = j; i >= 0; i--) {
    if (bs.at(i) == i+1)  return i;
  }
  throw "not found";
}

int main() {
  ll n;
  cin >> n;
  vector<ll> bs(n);
  for (ll i = 0; i < n; i++)  cin >> bs.at(i);

  vector<ll> ans(n);
  try {
    for (ll j = n-1; j >= 0; j--) {
      ll i = sch(j, bs);
      ans.at(j) = i+1;
      move(bs.begin()+i+1, bs.end(), bs.begin()+i);
    }
    for (auto x : ans)   cout << x << endl;
  }catch(const char* msg) {
    cout << -1 << endl;
  }
  return 0;
}
