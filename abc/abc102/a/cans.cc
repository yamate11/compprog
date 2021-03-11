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
  if (N % 2 == 0) {
    cout << N << endl;
  }else {
    cout << 2 * N << endl;
  }

  return 0;
}

