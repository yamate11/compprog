#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  // mapget, mapset

  map<A, B> mp;
  // or   unorderd_map<A, B> mp;

  * mapget(mp, a, def) returns mp[a] if it exists; returns def otherwise
  * mapset(mp, a, b, def) usually sets b as mp[a]; but erases a if b == def.

  ** NOTICE **
    Note that there is no default value for def.
    Providing typename MP::mapped_type() as the default value for def
    is problematic, as the generated value may become invalid when
    the function returns, although valgrind reports no problems.
    See https://atcoder.jp/contests/abc235/submissions/38297119.
    
  ** WARNING ** 
    If you use both mapget and mapset, be sure to use the SAME DEFAULT VALUE.


*/

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- mapget.cc

template<typename MP>
const typename MP::mapped_type& mapget(MP& mp,
            const typename MP::key_type& a,
            const typename MP::mapped_type& def) {
  auto it = mp.find(a);
  return it == mp.end() ? def : it->second;
}


template<typename MP, typename T>
void mapset(MP& mp,
            const typename MP::key_type& a,
            T&& val,
            const typename MP::mapped_type& def) {
  if (val == def) mp.erase(a);
  else mp[a] = forward<T>(val);
}

// @@ !! END ---- mapget.cc
