#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B, K, L; cin >> A >> B >> K >> L;
  ll c = min(B * (K / L) + A * (K % L), B * ((K+L-1) / L));
  cout << c << endl;

  return 0;
}

