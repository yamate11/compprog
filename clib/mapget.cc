#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  // mapget, mapset

  map<A, B> mp;

  * mapget(mp, a, def=B()) returns mp[a] if it exists; returns def otherwise
  * mapset(mp, a, b, def=B()) usually sets b as mp[a]; but erases a if b == def.

*/

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- mapget.cc

template<typename MP>
typename MP::mapped_type mapget(MP& mp,
            const typename MP::key_type& a,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  auto it = mp.find(a);
  return it == mp.end() ? def : it->second;
}


template<typename MP>
void mapset(MP& mp,
            const typename MP::key_type& a,
            typename MP::mapped_type&& val,
            const typename MP::mapped_type& def = typename MP::mapped_type()) {
  if (val == def) mp.erase(a);
  else mp[a] = forward<typename MP::mapped_type>(val);
}

// @@ !! END ---- mapget.cc
