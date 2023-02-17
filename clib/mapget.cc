#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  // mgs  (map_get and map_set)

  mgs<map<A, B>> mp;
  // or   mgs<unorderd_map<A, B>> mp;
  // Default value can be added:
  //      mgs<map<A, B>> mp(B());  mgs<unordered_map<A, B>> mp(B());

  * mp.get(a) returns mp[a] if it exists; returns default value otherwise
  * mp.set(a, b) usually sets b as mp[a]; but erases a if b == default value.

*/

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- mapget.cc

template<typename MP>
struct mgs : MP {
  using Key = typename MP::key_type;
  using T = typename MP::mapped_type;

  T def;

  mgs(const T& def_ = T()) : MP(), def(def_) {}
  mgs(const mgs& o) : MP(o), def(o.def) {}
  mgs(mgs&& o) : MP(move(o)), def(move(o.def)) {}
  mgs& operator =(const mgs& o) {
    MP::operator=(o);
    def = o.def;
    return *this;
  }
  mgs& operator =(mgs&& o) {
    MP::operator=(move(o));
    def = move(o.def);
    return *this;
  }

  const T& get(const Key& k) const {
    auto it = this->find(k);
    if (it == this->end()) return def;
    else return it->second;
  }

  template<typename T1>
  void set(const Key& k, T1&& t) {
    if (t == def) this->erase(k);
    else (*this)[k] = forward<T1>(t);
  }
};

// @@ !! END ---- mapget.cc
