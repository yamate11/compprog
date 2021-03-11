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
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (a % 2 == 1) continue;
    if (a % 3 == 0) continue;
    if (a % 5 == 0) continue;
    cout << "DENIED\n";
    return 0;
  }
  cout << "APPROVED\n";

  return 0;
}

