#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

void pout(string s) {
  cout << s << endl;
  exit(0);
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int k = A.at(0);
  int c = 1;
  int d = 0;
  for (int i = 1; i < N; i++) {
    if (A.at(i) == k) c++;
    else if (A.at(i) == k-1) d++;
    else if (A.at(i) == k+1) {
      if (d > 0) pout("No");
      d = c;
      c = 1;
      k = k + 1;
    }
    else pout("No");
  }
  if (d == 0) {
    if (2 * k <= N || k + 1 == N) pout("Yes");
    else pout("No");
  }else {
    if (2 * k - N <= d && d <= k - 1) pout("Yes");
    else pout("No");
  }

  return 0;
}

