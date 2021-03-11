#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int zero = 0;
  int one = 0;
  for(char c : s) {
    if (c == '0') {
      zero++;
    }else {
      one++;
    }
  }
  cout << 2*min(zero, one) << endl;
  return 0;
}

