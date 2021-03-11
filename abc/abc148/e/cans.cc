#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  if (n % 2 == 1) {
    cout << "0\n";
    return 0;
  }
  ll cnt = 0;
  ll div = 10;
  while (div <= n) {
    cnt += n / div;
    div *= 5;
  }
  cout << cnt << endl;

  return 0;
}

