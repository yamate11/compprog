#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll K; cin >> K;
  for (ll i = 0; i < K; i++) {
    if (S.at(i) != '1') {
      cout << S.at(i) << endl;
      return 0;
    }
  }
  cout << 1 << endl;

  return 0;
}

