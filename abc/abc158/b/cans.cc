#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A, B; cin >> N >> A >> B;
  ll c = A + B;
  ll k = N / c;
  ll m = N % c;
  cout << k * A + min(m, A) << endl;

  return 0;
}

