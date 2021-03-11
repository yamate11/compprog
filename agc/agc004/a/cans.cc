#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> v(3);
  for (int i = 0; i < 3; i++) {
    cin >> v.at(i);
    if (v.at(i) % 2 == 0) {
      cout << "0\n";
      return 0;
    }
  }
  sort(v.begin(), v.end());
  cout << v.at(0) * v.at(1) << endl;
  

  return 0;
}

