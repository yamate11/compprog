#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    if (a % 2 == 1) cnt = 1 - cnt;
  }
  cout << (cnt == 0 ? "YES\n" : "NO\n");

  return 0;
}

