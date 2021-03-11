#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto evenP = [&](auto pEvenP, auto pOddP, ll x) -> bool {
    if (x == 0) return true;
    return pOddP(pEvenP, pOddP, x - 1);
  };

  auto oddP = [&](auto pEvenP, auto pOddP, ll x) -> bool {
    if (x == 0) return false;
    return pEvenP(pEvenP, pOddP, x - 1);
  };

  cout << evenP(evenP, oddP, 3) << endl;
  cout << evenP(evenP, oddP, 6) << endl;

}
