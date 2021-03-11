#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll x = 1;
  while (N > 9) {
    N -= 9;
    x = x * 10 + 1;
  }
  cout << N * x << endl;

  return 0;
}

