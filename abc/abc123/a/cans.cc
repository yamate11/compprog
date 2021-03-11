#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<int> a(5);
  int k;
  cin >> a.at(0) >> a.at(1) >> a.at(2) >> a.at(3) >> a.at(4) >> k;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (abs(a.at(i) - a.at(j)) > k) {
	cout << ":(\n";
	return 0;
      }
    }
  }
  cout << "Yay!\n";

  return 0;
}

