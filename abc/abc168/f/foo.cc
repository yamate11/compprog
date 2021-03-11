#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

struct A {
  vector<int> vec;
  A() { cerr << "A()" << endl; }
  A(int x) : vec(x) { cerr << "A(" << x << ")" << endl; }
  A(const A& o) : vec(o.vec) {
    cerr << "A(const A&)" << endl;
  }
  A(A&& o) : vec(move(o.vec)) {
    cerr << "A(A&&)" << endl;
  }
  A& operator =(const A& o) {
    cerr << "operator=(const A&)" << endl;
    vec = vector<int>(o.vec);
    return *this;
  }
  A& operator =(A&& o) {
    cerr << "operator=(A&&)" << endl;
    vec = move(o.vec);
    return *this;
  }
  ~A() { cerr << "~A()" << endl; }
};


int main() {
  cerr << "Point0" << endl;
  A a1;
  A a2;
  deque<A> deq;
  cerr << "Point1" << endl;
  deq.push_back(move(a1));
  deq.push_back(move(a2));
  cerr << "Point2" << endl;
  A a3;
  a3 = move(deq.front()); deq.pop_front();
  cerr << "Point3" << endl;
}
