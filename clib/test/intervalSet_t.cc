#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(intervalSet)

// ---- inserted library file intervalSet.cc

using itv_elem_t = pair<ll, ll>;
using itv_set = set<itv_elem_t>;

// internal use
itv_set::iterator itv_right(itv_set& s, ll x) {
  return s.lower_bound(itv_elem_t(x + 1, x));
}

// Checks if x is in an interval in s.
//   Returns an iterator to [a, b) \in s such that x \in [a, b),
//   or s.end() if no such interval exisits.
itv_set::iterator itv_in(itv_set& s, ll x) {
  auto it = itv_right(s, x);
  if (it == s.begin()) return s.end();
  it--;
  if (x < it->second) return it;
  else                return s.end();
}

// Add a value x to interval set s, if x is not in Union(s).
//    Returns true if x was not in Union(s) and is now added.
//    Returns false if x was already in Union(s).
bool itv_add(itv_set& s, ll x) {
  auto it_r = itv_right(s, x);
  bool mg_r = false;
  if (it_r != s.end() && x + 1 == it_r->first) mg_r = true;
  bool mg_l = false;
  auto it_l = it_r;
  if (it_r != s.begin()) {
    it_l--;
    if (x < it_l->second)  return false;   // x is included in an interval.
    if (x == it_l->second) mg_l = true;
  }
  if (mg_l && mg_r) {
    s.emplace_hint(it_r, it_l->first, it_r->second);
    s.erase(it_l);
    s.erase(it_r);
  }else if (mg_l) {
    s.emplace_hint(it_r, it_l->first, it_l->second + 1);
    s.erase(it_l);
  }else if (mg_r) {
    s.emplace_hint(it_r, it_r->first - 1, it_r->second);
    s.erase(it_r);
  }else {
    s.emplace_hint(it_r, x, x + 1);
  }
  return true;
}

// Delete a value x from interval set s, if x is in Union(s).
//    Returns true if x was in Union(s) and is now deleted.
//    Returns false if x was not in Union(s).
bool itv_del(itv_set& s, ll x) {
  auto it = itv_in(s, x);
  if (it == s.end()) return false;
  auto nxt = it; nxt++;
  if (it->first == x && it->second == x + 1) {
    s.erase(it);
  }else if (it->first == x) {
    s.emplace_hint(nxt, it->first + 1, it->second);
    s.erase(it);
  }else if (it->second == x + 1) {
    s.emplace_hint(nxt, it->first, it->second - 1);
    s.erase(it);
  }else {
    s.emplace_hint(it, it->first, x);
    s.emplace_hint(nxt, x + 1, it->second);
    s.erase(it);
  }
  return true;
}

// Constructs an interval set from a sorted vector, typically vector<ll>.
itv_set from_sorted_vector(const auto& vec) {
  itv_set is;
  ll sz = vec.size();
  ll st = -1;
  for (ll i = 0; i < sz; i++) {
    if (i == 0 || vec[i-1] + 1 < vec[i])  {
      st = vec[i];
    }
    if (i+1 == sz || vec[i] + 1 < vec[i+1]) {
      is.emplace_hint(is.end(), st, vec[i] + 1);
    }
  }
  return is;
}

// ---- end intervalSet.cc

// @@ !! LIM -- end mark --

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

  
