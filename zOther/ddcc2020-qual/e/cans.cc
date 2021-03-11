#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int N;

char ask(int n, int k) {
  cout << "? " << n + 1;
  for (int i = 0; i < N-1; i++) cout << " " << ((k + i) % (2*N)) + 1;
  cout << endl;
  string T; cin >> T;
  if (T == "Red") return 'R';
  if (T == "Blue") return 'B';
  exit(1);
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cin >> N;
  char bl = ask(0, 1);
  char br = bl == 'R' ? 'B' : 'R';
  int l = 0;
  int r = N;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    char b = ask(mid, mid+1);
    if (b == bl) l = mid;
    else         r = mid;
  }
  char res[2*N+1];
  res[2*N] = 0;
  for (int i = 0; i < 2*N; i++) {
    if (i == l)          res[i] = bl;
    else if (i == l + N) res[i] = br;
    else if (i < l)      res[i] = ask(i, l+1);
    else if (i < l + N)  res[i] = ask(i, l+1 + N);
    else                 res[i] = ask(i, l+1);
  }
  cout << "! " << string(res) << endl;
  return 0;
}

