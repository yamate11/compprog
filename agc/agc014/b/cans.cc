#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, M; cin >> N >> M;
  vector<int> cnt(N);
  for (int i = 0; i < M; i++) {
    int p, q; cin >> p >> q; p--; q--;
    cnt.at(p)++;
    cnt.at(q)++;
  }
  for (int i = 0; i < N; i++) {
    if (cnt.at(i) % 2 == 1) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}

