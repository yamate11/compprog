#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B; cin >> A >> B;
  ll diffA = 0;
  if (A < 900) {
    diffA = 900 - (A / 100) * 100;
  }else if (A < 990) {
    diffA = 990 - (A / 10) * 10;
  }else {
    diffA = 999 - A;
  }
  ll diffB = 0;
  if (B >= 200) {
    diffB = (B / 100) * 100 - 100;
  }else if (B >= 110) {
    diffB = (B / 10) * 10 - 100;
  }else {
    diffB = B - 100;
  }

  cout << A - B + max(diffA, diffB) << endl;

  return 0;
}

