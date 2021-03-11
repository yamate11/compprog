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
  
  int k = 1;
  for (int p = 0; p < M; p++) k *= 2;
  cout << k * (1900*M + 100* (N-M)) << endl;

  return 0;
}

