#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Unordered Map with safe hash map (and better performance)

  C++ unordered_map is not safe (especially for Codeforces) as its default hash function is fragile
  to collision attacks.  The safe_custom_hash function defined in this file is more robust.
  PBDS gp_hash_table is an altenative to unordered_map with better performance, and also fragile.
  Thus, using gp_hash_table with safe_custom_hash may be the best practice.

  Usage:

###     NOT WORKING PROPERLY with user defined struct
#    using mymap = gp_hash_table<T_key, T_value, safe_custom_hash>;
#    // Now, mymap can be used almost same as unordered_map<T_key, T_value>
###
    
    // The following also works, but maybe you do not need to do that.
    using mymap = unordered_map<T_key, T_value, safe_custom_hash>;

*/

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- unordered_map.cc

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
*/

struct safe_custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// @@ !! END ---- unordered_map.cc
