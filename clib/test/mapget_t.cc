#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(mapget)

// ---- inserted library file mapget.cc
#line 25 "/home/y-tanabe/proj/compprog/clib/mapget.cc"

template<typename MP>
typename MP::mapped_type mapget(MP& mp,
            const typename MP::key_type& a,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  auto it = mp.find(a);
  return it == mp.end() ? def : it->second;
}


template<typename MP, typename T>
void mapset(MP& mp,
            const typename MP::key_type& a,
            T&& val,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  if (val == def) mp.erase(a);
  else mp[a] = forward<T>(val);
}

// ---- end mapget.cc

// @@ !! LIM -- end mark --
#line 7 "mapget_skel.cc"

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
  {
    map<ll, ll> mp;
    mapset(mp, 1, 1); // constant
    ll x = 2;
    mapset(mp, 2, x); // l-value
    const ll y = 3;
    mapset(mp, 3, y); // const l-value
    mapset(mp, 4, move(x)); // r-value
    assert(mapget(mp, 1) == 1);
    assert(mapget(mp, 2) == 2);
    assert(mapget(mp, 3) == 3);
    assert(mapget(mp, 4) == 2);
  }
  {
    using vi = vector<int>;
    map<int, vi> mp;
    mapset(mp, 3, vi{1, 2, 3});
    mapset(mp, 7, move(vi{-1, -2}));
    mapset(mp, 10, vi{});
    assert(mapget(mp, 3) == (vi{1, 2, 3}));
    assert(mapget(mp, 7) == (vi{-1, -2}));
    assert(mapget(mp, 10) == vi{});
    assert(mapget(mp, 100000) == vi{});
    assert(mp.find(10) == mp.end());
    mapset(mp, 7, vi{});
    assert(mp.size() == 1);
  }
  {
    using mis = map<int, string>;
    map<int, string> mp{{5, "hello"}, {2, "world"}};
    mapset(mp, 4, "", "---");
    mapset(mp, 7, "---", "---");
    assert(mapget<mis>(mp, 2, string("---")) == "world");
    assert(mapget<mis>(mp, 7, string("---")) == "---");
    assert(mapget<mis>(mp, -10, string("---")) == "---");
  }
}
