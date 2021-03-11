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
  ll k = N % 10;
  if (k == 0 || k == 1 || k == 6 || k == 8) {
    cout << "pon\n";
  }else if (k == 3) {
    cout << "bon\n";
  }else {
    cout << "hon\n";
  }

  return 0;
}

