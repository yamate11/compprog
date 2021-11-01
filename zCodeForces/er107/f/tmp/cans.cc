#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#include <boost/range/irange.hpp>

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> v1 = {1, 2, 3, 4, 5};
  vector<ll> v2 = {3, 4, 5, 6, 7};

  if (0) {
    auto rng = boost::irange(0, 5);
    bool chk = all_of(rng.begin(), rng.end(), [&](int i) -> bool {
      return v1[i] < v2[i];
    });
    cout << chk << endl;
  }
  
  return 0;
}

