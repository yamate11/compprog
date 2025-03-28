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
  vector A(N, 0LL);
  ll s = 0;
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);
    s ^= A.at(i);
  }
  for (ll i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << (s ^ A.at(i));
  }
  cout << endl;

  return 0;
}

