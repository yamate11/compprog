#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N; cin >> H >> W >> N;
  ll x = max(H, W);
  ll c = (N + x-1) / x;
  cout << c << endl;

  return 0;
}

