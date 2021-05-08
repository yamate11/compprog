#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(intervalSet)

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    vector<ll> vec({2,3,4,10,13,14});
    itv_set is = from_sorted_vector(vec);
    itv_set ref;
    ref.emplace(2, 5);
    ref.emplace(10, 11);
    ref.emplace(13, 15);
    assert(is == ref);
  }
  {
    vector<ll> vec;
    itv_set is = from_sorted_vector(vec);
    assert(is == itv_set());
  }
  {
    vector<ll> vec({5});
    itv_set is = from_sorted_vector(vec);
    itv_set ref;
    ref.emplace(5, 6);
    assert(is == ref);
  }
  {
  itv_set is;
    itv_add(is, 2);
    itv_add(is, 7);
    itv_add(is, 4);
    itv_add(is, 3);
    itv_add(is, 9);
    itv_add(is, 11);
    itv_add(is, 8);
    itv_add(is, 10);
    {
      vector<ll> vec({2,3,4,7,8,9,10,11});
      assert(is == from_sorted_vector(vec));
    }
    itv_del(is, 7);
    {
      vector<ll> vec({2,3,4,8,9,10,11});
      assert(is == from_sorted_vector(vec));
    }
    itv_del(is, 4);
    {
      vector<ll> vec({2,3,8,9,10,11});
      assert(is == from_sorted_vector(vec));
    }
    itv_del(is, 10);
    {
      vector<ll> vec({2,3,8,9,11});
      assert(is == from_sorted_vector(vec));
      itv_del(is, 5);
      assert(is == from_sorted_vector(vec));
    }
    itv_add(is, 5);
    {
      vector<ll> vec({2,3,5,8,9,11});
      assert(is == from_sorted_vector(vec));
      itv_del(is, 5);
      vector<ll> vec1({2,3,8,9,11});
      assert(is == from_sorted_vector(vec1));
    }
    itv_add(is, 1);
    {
      vector<ll> vec({1,2,3,8,9,11});
      assert(is == from_sorted_vector(vec));
    }
    itv_add(is, 12);
    {
      vector<ll> vec({1,2,3,8,9,11,12});
      assert(is == from_sorted_vector(vec));
    }
    itv_add(is, 14);
    {
      vector<ll> vec({1,2,3,8,9,11,12,14});
      assert(is == from_sorted_vector(vec));
    }
    itv_add(is, 13);
    {
      vector<ll> vec({1,2,3,8,9,11,12,13,14});
      assert(is == from_sorted_vector(vec));
    }
    itv_add(is, 5);
    {
      vector<ll> vec({1,2,3,5,8,9,11,12,13,14});
      assert(is == from_sorted_vector(vec));
    }
    for (ll i = 0; i <= 10; i++) {
      auto it = itv_in(is, i);
      if ((1 <= i && i <= 3) || i == 5 || (8 <= i && i <= 9)) {
        assert(it != is.end() && it->first <= i && i < it->second);
      }else {
        assert(it == is.end());
      }
    }
  }
  cout << "ok\n";
}

  
