#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N;
  cin >> N;
  double x = (double)N / 1.08;
  int p = floor(x) - 1;
  for (int i = 0; i <= 2; i++) {
    int y = floor((double)(p + i) * 1.08);
    if (y == N) {
      cout << p+i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  
  return 0;
}

