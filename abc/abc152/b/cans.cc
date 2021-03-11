#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll a, b; cin >> a >> b;
  if (b < a) swap(a, b);
  for (ll i = 0; i < b; i++) {
    cout << a;
  }
  cout << endl;

  return 0;
}

