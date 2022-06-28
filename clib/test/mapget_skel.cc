#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mapget)

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    map<ll, ll> mp{{1, 5}, {7, -1}};
    assert(mapget(mp, 1) == 5);
    assert(mapget(mp, 7) == -1);
    assert(mapget(mp, 100) == 0);
    assert(mp.find(100) == mp.end());
    mapset(mp, 4, 2);
    assert(mapget(mp, 4) == 2);
    mapset(mp, 7, 0);
    assert(mapget(mp, 7) == 0);
    assert(mp.find(7) == mp.end());
  }
}
