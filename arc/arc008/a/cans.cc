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
  ll a = N / 10;
  ll b = N % 10;
  ll tot = a * 100;
  if (b <= 6) tot += b * 15;
  else tot += 100;
  cout << tot << endl;

  return 0;
}

