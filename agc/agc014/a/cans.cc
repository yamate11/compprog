#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int A, B, C; cin >> A >> B >> C;
  if (A == B && B == C && A % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  int count = 0;
  while (true) {
    if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
      cout << count << endl;
      return 0;
    }
    int a = (B + C) / 2;
    int b = (A + C) / 2;
    int c = (A + B) / 2;
    A = a;
    B = b;
    C = c;
    count++;
  }

  return 0;
}

