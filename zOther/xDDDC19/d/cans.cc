#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll M; cin >> M;
  vector<ll> d(M), c(M);
  for (int i = 0; i < M; i++) cin >> d.at(i) >> c.at(i);
  ll sum = 0;
  ll numD = 0;
  for (int i = 0; i < M; i++) {
    sum += d.at(i) * c.at(i);
    numD += c.at(i);
  }
  cout << (sum - 1) / 9 + numD - 1 << endl;

  return 0;
}

