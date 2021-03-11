#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

void fin() {
  cout << -1 << endl;
  exit(0);
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  ll p = 2 * K - 1;
  if (!(p <= N)) fin();

  auto diff = [&](int i) -> int {
    if (i < p / 2) {
      return -2 * i + (p/2) - 1;
    }else {
      return -2 * (i - p/2) + (p+1)/2 - 1;
    }
  };

  for (int i = 0; i < p; i++) {
    cout << K + N - 1 - i << " "
	 << K + N + i + diff(i) << " "
	 << K + 2*N + p/2 + diff(i) << "\n";
  }
  for (int i = p; i < N; i++) {
    cout << K + N - 1 - i << " "
	 << K + N + i << " "
	 << K + 2*N + i << "\n";
  }

  return 0;
}

