#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int A, B; cin >> A >> B;
  vector<bool> p(4);
  p.at(A) = true;
  p.at(B) = true;
  for (int i = 1; i <= 3; i++) {
    if (!p.at(i)) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

