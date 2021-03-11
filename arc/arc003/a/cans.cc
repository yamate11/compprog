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
  string S; cin >> S;
  ll tot = 0;
  for (ll i = 0; i < N; i++) {
    if (S.at(i) == 'F') continue;
    tot += 'E' - S.at(i);
  }
  cout << (double)tot / N << endl;

  return 0;
}

