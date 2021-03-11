#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<int> a(6);
  for (int i = 0; i < 6; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  cout << a.at(3) << endl;

  return 0;
}

