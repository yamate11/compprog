#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B, C; cin >> A >> B >> C;
  ll K; cin >> K;
  ll t = 0;
  while (A >= B) {
    B *= 2;
    t++;
  }
  while (B >= C) {
    C *= 2;
    t++;
  }
  if (t <= K) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}

