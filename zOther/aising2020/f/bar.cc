#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

optional<vector<int>> func1() {
  vector<int> ret(10);
  ret[5] = 100;
  return make_optional(move(ret));
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto optvec = func1();
  if (!optvec.has_value()) { return 0; }
  auto vec = optvec.value();
  cout << vec[5] << endl;
  vec[5] = 10;
  cout << vec[5] << endl;

  return 0;
}
