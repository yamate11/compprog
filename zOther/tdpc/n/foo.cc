#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  optional<int> p;
  p = optional<int>();
  if (p) {
    cout << 1 << endl;
  }else {
    cout << 2 << endl;
  }
  p = optional<int>(10);
  if (p) {
    cout << 3 << endl;
  }else {
    cout << 4 << endl;
  }
  p = optional<int>(0);
  if (p) {
    cout << 5 << endl;
  }else {
    cout << 6 << endl;
  }
  p = 10;
  cout << *p << endl;

  return 0;
}
