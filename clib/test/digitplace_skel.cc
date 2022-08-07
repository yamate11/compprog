#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(digitplace)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    DigitPlace dgp(10);
    assert (dgp.ll2str(123) == "123");
    assert (dgp.ll2str(1) == "1");
    assert (dgp.ll2str(0) == "0");
    assert (dgp.str2ll("82") == 82);
    assert (dgp.str2ll("0") == 0);
    assert (dgp.str2ll("1") == 1);
    assert (dgp.mag(0) == 0);
    assert (dgp.mag(1) == 1);
    assert (dgp.mag(9) == 1);
    assert (dgp.mag(10) == 2);
    assert (dgp.mag(99) == 2);
    assert (dgp.mag(100) == 3);
    assert (dgp.mag(LLONG_MAX) == 19);
    assert (dgp.basepow(0) == 1);
    assert (dgp.basepow(1) == 10);
    assert (dgp.basepow(18) == 1000000000000000000);
    assert (dgp.vecdigits(0) == vector<int>{0});
    assert ((dgp.vecdigits(1729) == vector<int>{9,2,7,1}));
  }
  {
    DigitPlace dgp(2);
    assert (dgp.ll2str(17) == "10001");
    assert (dgp.ll2str(0) == "0");
    assert (dgp.str2ll("10101") == 21);
    assert (dgp.str2ll("0") == 0);
    assert (dgp.mag(0) == 0);
    assert (dgp.mag(1) == 1);
    assert (dgp.mag(2) == 2);
    assert (dgp.mag(3) == 2);
    assert (dgp.mag(4) == 3);
    assert (dgp.mag(LLONG_MAX) == 63);
    assert (dgp.basepow(0) == 1);
    assert (dgp.basepow(1) == 2);
    assert (dgp.basepow(62) == 1LL << 62);
    assert (dgp.vecdigits(0) == vector<int>{0});
    assert ((dgp.vecdigits(30) == vector<int>{0, 1, 1, 1, 1}));
  }

  return 0;
}

