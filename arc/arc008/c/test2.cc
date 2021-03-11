#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct A {
  ll size;
  vector<ll> val;
  ll getVal(ll i) { return val.at(i); }
};

ll func1(A a) {
  ll tot = 0;
  for (int i = 0; i < a.size; i++) tot += a.val.at(i);
  return tot;
}

template <class T>
ll func2(T t) {
  ll tot = 0;
  for (int i = 0; i < t.size; i++) tot += t.getVal(i);
  return tot;
}

int main() {
  A a;
  a.size = 1e8;
  a.val = vector<ll>(a.size);
  for (ll i = 0; i < a.size; i++) a.val.at(i) = i;
  auto start1 = chrono::system_clock::now();
  ll x = func1(a);
  auto mid1 = chrono::system_clock::now();
  ll y = func2<A>(a);
  auto end1 = chrono::system_clock::now();
  assert(x == y);
  cout << (mid1 - start1).count() << endl;
  cout << (end1 - mid1).count() << endl;
}
