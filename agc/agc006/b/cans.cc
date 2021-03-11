#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, x; cin >> N >> x;
  int K = 2 * N - 1;
  if (x == 1 || x == K) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes\n";
  if (N == 2) {
    cout << "1\n2\n3\n";
    return 0;
  }
  vector<int> p(K);
  int lmin = N-2;
  int lmax = N;
  if (x+2 <= K) {
    p.at(N-3) = x+2;
    lmin = N-3;
  }
  p.at(N-2) = x-1;
  p.at(N-1) = x;
  p.at(N)   = x+1;
  if (x-2 >= 1) {
    p.at(N+1) = x-2;
    lmax = N+1;
  }
  int y = 1;
  int i = 0;
  while (i < K) {
    if (i == lmin) {
      i = lmax + 1;
      continue;
    }
    if (x-2 <= y && y <= x+2) {
      y = x + 3;
    }
    p.at(i) = y;
    i++;
    y++;
  }
  for (int j = 0; j < K; j++) cout << p.at(j) << "\n";

  return 0;
}

