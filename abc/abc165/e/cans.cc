#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;

  ll xL = 1;
  ll xH = xL + M;
  ll yL = xH + 1;
  ll yH = yL + (M-1);
  while (true) {
    if (xL >= xH) break;
    cout << xL << " " << xH << "\n";
    if (yL >= yH) break;
    cout << yL << " " << yH << "\n";
    xL += 1;
    xH -= 1;
    yL += 1;
    yH -= 1;
  }

  return 0;
}

