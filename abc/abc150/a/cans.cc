#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K, X; cin >> K >> X;
  if (K * 500 >= X) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

