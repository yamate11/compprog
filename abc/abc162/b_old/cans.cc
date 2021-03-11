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
  ll sum = 0;
  for (ll i = 1; i <= N; i++) {
    if (i % 3 == 0 || i % 5 == 0) continue;
    sum += i;
  }
  cout << sum << endl;

  return 0;
}

