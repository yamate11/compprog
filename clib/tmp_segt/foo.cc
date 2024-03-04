#include <bits/stdc++.h>

using namespace std;


template <typename A>
struct S {
  vector<A> vec;
  struct Proxy {
    S<A>& parent;
    int idx;
    Proxy(S<A>& p, int i) : parent(p), idx(i) {}
    Proxy& operator =(const A& a) {
      parent.vec[idx] = a;
      return *this;
    }
    operator A() { return parent.vec[idx]; }
  };
  const A& operator [](int i) const {
    cerr << "const" << endl;
    return Proxy(*this, i);
  }
  A operator [](int i) {
    cerr << "non-const" << endl;
    return Proxy(*this, i);
  }
  S() : vec(10) {}
};

using pii = pair<int, int>;

int main() {

  S<pii> s;
  s[0] = pii(2, 4);
  const pii t = s[0];
  cout << s[0].first << "\n";

}

