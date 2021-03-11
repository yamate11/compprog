#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

char foo(char b) {
  if (b == 'A') return 'T';
  if (b == 'T') return 'A';
  if (b == 'C') return 'G';
  if (b == 'G') return 'C';
  return 'x';
}

int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  char b; cin >> b;
  cout << foo(b) << endl;

  return 0;
}

