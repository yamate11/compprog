#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
using ull = unsigned long long;

// @@ !! LIM(digit)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    digit_util du;
    assert(du.pow_size() == 19);
    assert(du.pow(0) == 1);
    assert(du.pow(1) == 10);
    assert(du.pow(6) == 1000000);
    assert(du.pow(18) == 1000000000000000000);
    assert(du.width(1) == 1);
    assert(du.width(2) == 1);
    assert(du.width(9) == 1);
    assert(du.width(10) == 2);
    assert(du.width(99) == 2);
    assert(du.width(100) == 3);
    assert(du.nd_min(1) == 1);
    assert(du.nd_min(2) == 10);
    assert(du.nd_min(3) == 100);
    assert(du.nd_max(1) == 9);
    assert(du.nd_max(2) == 99);
    assert(du.nd_max(3) == 999);
    assert(du.width(123456789012345678) == 18);
    assert(du.width(1000000000000000000) == 19);
    assert(du.floor(0) == 0);
    assert(du.floor(123) == 100);
    assert(du.floor(1000) == 1000);
    assert(du.ceil(0) == 0);
    assert(du.ceil(123) == 1000);
    assert(du.ceil(1000) == 1000);
    assert(du.to_string(0) == "0");
    assert(du.to_string(1) == "1");
    assert(du.to_string(123) == "123");
    assert(du.from_string("0") == 0);
    assert(du.from_string("230") == 230);
    assert(du.from_string("00230") == 230);
    assert(du.to_vector(0) == vector<ll>{0});
    assert(du.to_vector(1) == vector<ll>{1});
    assert(du.to_vector(123) == (vector<ll>{1, 2, 3}));
    assert(du.from_vector(vector<ll>{0}) == 0);
    assert(du.from_vector((vector<ll>{2, 3, 0})) == 230);
    assert(du.from_vector((vector<ll>{0, 0, 2, 3, 0})) == 230);
  }

  {
    digit_util du(3);
    assert(du.pow(0) == 1);
    assert(du.pow(4) == 81);
    assert(du.width(80) == 4);
    assert(du.floor(80) == 27);
    assert(du.ceil(80) == 81);
    assert(du.to_string(83) == "10002");
    assert(du.from_string("10002") == 83);
  }

  {
    digit_util du(16);
    assert(du.pow(0) == 1);
    assert(du.pow(4) == 65536);
    assert(du.width(100) == 2);
    assert(du.floor(100) == 16);
    assert(du.ceil(100) == 256);
    assert(du.to_string(254) == "fe");
    assert(du.to_string(254, true) == "FE");
    assert(du.from_string("1af") == 256 + 10 * 16 + 15);
    assert(du.from_string("1AF") == 256 + 10 * 16 + 15);
  }

  cerr << "ok\n";

  return 0;
}
