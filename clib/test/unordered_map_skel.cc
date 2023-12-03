#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(unordered_map)

int main() {

  /*
  {
    using mymap = gp_hash_table<ll, ll, safe_custom_hash>;
    mymap mp;
    mp[10] = mp[20] + 100;
    assert(mp.find(0) == mp.end());
    assert(mp.find(10) != mp.end());
    assert(mp.find(20) != mp.end());
    assert(mp[10] == 100);
    assert(mp[20] == 0);
  }
  */

  {
    using mymap = unordered_map<ll, ll, safe_custom_hash>;
    mymap mp;
    mp[10] = mp[20] + 100;
    assert(mp.find(0) == mp.end());
    assert(mp.find(10) != mp.end());
    assert(mp.find(20) != mp.end());
    assert(mp[10] == 100);
    assert(mp[20] == 0);
  }

  cerr << "ok." << endl;
}

