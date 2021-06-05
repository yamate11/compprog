#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

using pair_t = pair<int, int>;
using ordered_set = tree<
  pair_t,
  null_type,                 
  less<pair_t>,
  rb_tree_tag,                         
  tree_order_statistics_node_update    
  >;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ordered_set os;
  os.insert(pair_t(0,0));
  os.insert(pair_t(1,0));
  os.insert(pair_t(1,1));
  os.insert(pair_t(2,0));
  os.insert(pair_t(2,1));

  assert(os.order_of_key(pair_t(-1,0)) == 0);
  assert(os.order_of_key(pair_t(0,0)) == 0);
  assert(os.order_of_key(pair_t(0,1)) == 1);
  assert(os.order_of_key(pair_t(1,0)) == 1);
  assert(os.order_of_key(pair_t(1,1)) == 2);
  assert(os.order_of_key(pair_t(100,0)) == 5);

  assert(*os.find_by_order(0) == pair_t(0,0));
  assert(*os.find_by_order(2) == pair_t(1,1));
  assert(*os.find_by_order(4) == pair_t(2,1));
  assert(os.find_by_order(5) == os.end());

  return 0;
}
