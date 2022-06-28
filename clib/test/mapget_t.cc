#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mapget)

// ---- inserted library file mapget.cc

template<typename MP, typename A = typename MP::key_type, typename B = typename MP::mapped_type>
B mapget(const MP& mp, const A& a) {
  auto it = mp.find(a);
  if (it == mp.end()) return B();
  return it->second;
}

template<typename MP, typename A = typename MP::key_type, typename B = typename MP::mapped_type>
void mapset(MP& mp, const A& a, B val) {
  if (val == B()) mp.erase(a);
  else            mp[a] = val;
}

// ---- end mapget.cc

// @@ !! LIM -- end mark --

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
