#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S, T; cin >> S >> T;
  ll N = S.size();
  for (ll st = 0; st < N; st++) {
    bool ok = true;
    for (ll i = 0; i < N; i++) {
      if (S.at(i) == T.at((st + i) % N)) continue;
      ok = false;
      break;
    }
    if (ok) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

