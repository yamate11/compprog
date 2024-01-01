#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(UndoUnionFind)

int main() {
  {
    UndoUnionFind uuf(5);
    uuf.merge(0, 1);
    uuf.merge(1, 2);
    assert(uuf.leader(0) == uuf.leader(2));
    uuf.undo();
    assert(uuf.leader(0) != uuf.leader(2));
    assert(uuf.leader(2) == 2);
    uuf.merge(1, 3);
    assert(uuf.leader(0) == uuf.leader(3));
    assert(uuf.leader(2) != uuf.leader(3));
    assert(uuf.gsize(0) == 3);
    uuf.merge(0, 3);
    uuf.undo();
    assert(uuf.leader(0) == uuf.leader(3));
    uuf.undo();
    assert(uuf.leader(0) != uuf.leader(3));
  }

  cerr << "ok\n";
  
  return 0;
}


