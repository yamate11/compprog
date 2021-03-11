#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct A {
  ll size;
  vector<vector<ll>> val;
  ll getNumNbr(ll i) { return i; }
  ll getNbr(ll i, ll j) { return val.at(i).at(j); }
};

ll func1(A a) {
  ll tot = 0;
  for (int i = 0; i < a.size; i++) {
    ll sub = 1;
    for (int j = 0; j < i; j++) sub *= a.val.at(i).at(j);
    tot += sub;
  }
  return tot;
}

ll func2(A a) {
  ll tot = 0;
  for (int i = 0; i < a.size; i++) {
    ll sub = 1;
    for (int j = 0; j < a.getNumNbr(i); j++) sub *= a.getNbr(i, j);
    tot += sub;
  }
  return tot;
}

int main() {
  A a;
  a.size = 1e3;
  a.val = vector<vector<ll>>(a.size, vector<ll>(a.size));
  for (ll i = 0; i < a.size; i++) {
    for (ll j = 0; j < i; j++) {
      a.val.at(i).at(j) = 1 + i + j;
    }
  }
  auto start1 = chrono::system_clock::now();
  ll x = func1(a);
  auto mid1 = chrono::system_clock::now();
  ll y = func2(a);
  auto end1 = chrono::system_clock::now();
  assert(x == y);
  cout << (mid1 - start1).count() << endl;
  cout << (end1 - mid1).count() << endl;
}
