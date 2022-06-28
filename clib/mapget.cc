#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  // mapget, mapset

  map<A, B> mp;

  * mapget(map<A, B>& mp, A a) returns mp[a] if it exists; returns B() otherwise
  * mapset(map<A, B>& mp, A a, B b) usually sets b as mp[a]; but erases a if b == B().

*/

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- mapget.cc

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

// @@ !! END ---- mapget.cc
