#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int K = (int)(1e5) + 1;

  int N; cin >> N;
  vector<int> S(K);
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    S.at(a)++;
  }
  int even = 0;
  int odd = 0;
  for (int i = 0; i < K; i++) {
    if (S.at(i) == 0) continue;
    else if (S.at(i) % 2 == 0) even++;
    else odd++;
  }
  int ans = even % 2 == 0 ? odd + even : odd + even - 1;
  cout << ans << endl;

  return 0;
}

