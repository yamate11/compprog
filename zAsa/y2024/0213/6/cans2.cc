#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll cnt = 0;
  for (ll a = 1; a <= N; a++) {
    for (ll b = 1; b <= N; b++) {
      if (a * b < N) cnt++;
      else break;
    }
  }
  cout << cnt << endl;

  return 0;
}

