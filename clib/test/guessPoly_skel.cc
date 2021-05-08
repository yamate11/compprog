#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug guessPoly)


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto f = [](ll i, ll j) -> ll {
    return (2 + j) * i*i + (5 - j) * i + 4 * j;
  };
  vector<double> v;
  for (ll i = 0; i < 100; i++) {
    for (ll j = 0; j < 3; j++) {
      v.push_back(f(i, j));
    }
  }
  GuessPoly<double, 0> gp(v, 0, 2, 3, 10);
  assert(gp.comp(600) == f(200, 0));
  assert(gp.comp(601) == f(200, 1));
  assert(gp.comp(602) == f(200, 2));

  return 0;
}

